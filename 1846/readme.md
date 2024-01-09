# C. [Rudolf and the Another Competition](https://codeforces.com/problemset/problem/1846/C)

## 问题描述

给定整数n、m、h，和一个n行m列的矩阵a。现在要求每行a[i]的积分和罚时。



求积分的过程是：

1. 选择尽可能多的元素并加到b中，要求：b的和不超过h。b的长度就是积分



求罚时的过程是：

1. 假设b的长度是k，那么按照顺序从前往后选择的 b[1]  * k + b[2] * (k - 1) + ... + b[k] * 1的和即是罚时。



最后只需要输出a[1]的积分和罚时排名第几，即可。



积分不同，按照积分从高到低。

积分相同，按照罚时从低到高。

如果都相同，a[1]排名优先。



## 问题思路

注意每行计算都是独立的，不妨单独求出每行得到积分和罚时，再自定义排序并输出结果。



关键是是如何求出b。注意到积分优先，即需要元素加的尽可能多，所以应该贪心地从小到大加。

因此，需要对每行a[i]排序，使得a[i] < a[i+1]，我们只需要从前往后遍历并保证和 <= h即可。



得到b后，想办法求出最小的罚时（按照题目要求）。因为可以改变顺序，而且长度此时已经固定了，所以肯定是需要刚开始选择的元素最少比较好。也就是从小到大开始选。所以，在计算积分的时候，可以顺带计算罚时。



总结：

定义b[i].id=原本编号，b[i].a = 积分, b[i].b = 罚时，我们只需要求出长度n的b，再排序，最后输出b[i].id=1的位置即可。自定义排序不再赘述。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, m, h, a[200001];

struct Node {
	int id, a;
	long long b;
	
	bool operator<(const Node& n) const {
		if(a == n.a) {
			if(b == n.b) return id < n.id;
			return b < n.b;
		}
		return a > n.a;
	}
} b[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m >> h;
		for(int i = 1; i <= n; i++) {
			b[i].id = i;
			
			for(int j = 0; j < m; j++) {
				std::cin >> a[j];
			}
			
			std::sort(a, a+m);
			
			int sum = 0, cnt = 0;
			long long cur = 0;
			
			for(int j = 0; j < m && sum + a[j] <= h; j++) {
				sum += a[j];
				cnt++;
				cur += sum;
			} 
			
			b[i].a = cnt;
			b[i].b = cur;
		}
		
		std::sort(b+1, b+n+1);
		
		for(int i = 1; i <= n; i++) {
			if(b[i].id == 1) {
				std::cout << i << "\n"; 
				break;
			}
		}
	}
	return 0;
}
```



## 要点

贪心



# D. [Rudolph and Christmas Tree](https://codeforces.com/problemset/problem/1846/D)

## 问题描述

 给定整数d和h表示1个等腰三角形的宽和高。现在有n个这样的三角形，它们放在y轴坐标上，每个都是这样放着（建议看官网的图）：



  \*

 \*\*

\* \* \*



给定长度n的数组a，a[i] 表示第 i 三角形的底在y轴上的坐标。现在要求所有三角形的面积的并。



## 问题思路

最简单就是所有三角形都不重叠，直接三角形面积公式 * n即可。



尝试从下往下数三角形。



如何判断重叠呢？



显然，如果 a[i+1] < a[i] + h，就代表重叠了。



如果当前三角形没有和上面的三角形重叠，那么很好，加上这个三角形的面积。

否则，我们需要去掉重叠的部分，重叠部分刚好 和a[i] 表示的三角形是相似三角形，于是有：



上三角形宽/a[i]宽=上三角形的高/a[i]的高

也就是：上三角形宽/d= h-(a[i+1]-a[i])  / h 。拿到了上三角形的宽，发现贡献的面积刚好是个梯形，直接用梯形面积公式即可。



所以 当前三角形的贡献的面积是：

( (h-(a[i+1]-a[i]) ) / h * d + d ) * (a[i+1]-a[i]) / 2

令x = a[i+1] - a[i]，于是 S =  （(h-x) / h * d + d) * x / 2



总结：

因为题目a[i] < a[i+1]，所以倒序遍历a，使用i，i从n-2到0。初始化sum = h * d / 2

对于当前i：

​	如果a[i + 1] < a[i] + h，（(h-x) / h * d + d) * x / 2

​	否则，sum += h * d / 2



最后输出 sum



## 实现代码

```c++
#include<iostream>
#define ld long double 

int t, n, a[200001];
long long d, h;

int main() {
	std::cout.precision(10); std::cout.setf(std::ios::fixed);
	
	std::cin >> t;
	while(t--) {
		std::cin >> n >> d >> h;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		ld sum = (ld)d * h / 2.0;
		
		for(int i = n - 2; i >= 0; i--) {
			if(a[i+1] < a[i] + h) {
				ld x = a[i+1] - a[i];
				sum += ((h-x) / h * d + d) * x / 2.0;
			} else {
				sum += (ld)d * h / 2.0;
			}
		}
		
		std::cout << sum << "\n";
	}
	return 0;
}
```



## 要点

注意到：

1. a[i]只需要关注被a[i+1]覆盖的部分，与a[i+2]及以后无关

2. a[i]被覆盖后会得到一个梯形
3. 可以通过相似三角形求出梯形的上底