# A. [Mean Inequality](https://codeforces.com/problemset/problem/1526/A)

## 问题描述

给2*n个整数，要求重新排列，满足：

1. 任意一个数不是左右邻居的算术平均数。
2. 对于第一个它的左邻居是最后一个元素，最后一个的右邻居是第一个元素。



## 问题思路

先排序保证：a1 < a2 < ... < an



n=2时，有：

a < b < c <d

c a d c  : 显然相邻的元素的平均数要么大于，要么小于



n=3时，有：

a < b < c < e < f < g

e a f b g c：依旧满足。

a e b f c g: 依旧满足



猜想：排序后，循环i从1到n，输出a[i] a[i+n]

## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[60];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n*2; i++) {
			std::cin >> a[i]; 
		}
		std::sort(a+1, a+1+n*2);
		
		for(int i = 1; i <= n; i++) {
			std::cout << a[i] << " " << a[i+n] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```





## 要点

排序

# C. [Potions](https://codeforces.com/problemset/problem/1526/A)

## 问题描述

给定长度n的整数数组a，一开始x=1，从前往后循环a时可以选择或者不选择a[i]。如果选择了a[i]，那么x = x + a[i]。



现在要求循环a的过程中，x始终>0，现在问：可以选择的最大数量是多少？



## 问题思路

因为无论a[i]的值多少，都是贡献1，所以我们需要贪心地选择最大值：



我们可以选择所有a[i] >= 0的数，显然最大值一定是 大于等于 a[i] >=0的数量



现在考虑小于0的数，这时候不能再从小的开始选择，因为取值是有先后顺序的。



因此，我们应该从前往后走的时候，时刻记录最小值，如果x += a[i] 不满足题意，那么我们不停地把最小值给扔掉。显然这是最优的结果。



为了维护这个最小值，可以使用优先队列。（其实这道题目也是经典的优先队列的运用）



## 实现代码

C1和C2的代码几乎一样，这里只放C2的

```c++
#include<iostream>
#include<queue>

int n, a[200000];
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int ans = 0;
	long long sum = 1;
	for(int i = 0; i < n; i++) {
		ans++;
		sum += a[i];
		pq.push(a[i]);
		
		while(sum < 1 && !pq.empty()) {
			int x = pq.top(); pq.pop();
			ans--;
			sum -= x;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}

```





## 要点

优先队列

