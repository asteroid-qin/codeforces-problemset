# B. [Optimal Reduction](https://codeforces.com/problemset/problem/1713/B)

## 问题描述

给定长度n的数组a，确保在数组a的所有排列中，a的价值最小。a的价值定义为：执行区间值-1操作，使得a变为全0数组的最小操作数。



## 问题思路

倒着思考：

显然，如果a是顺序或者倒序，a的价值是最小的，并且为数组a的最大值。



所以，我们只需要计算给定的数组a的价值，判断是否大于等于即可。



那么如何线性计算最大价值呢？可以从最大值开始，找左右的最小值。



发现结论：最大值必须是峰顶，左右则是单调递减。否则会出现断层，绝对劣于顺序排列。



问题变为了：判断数组是否先增后减。



## 实现代码

```c++
#include<iostream>


int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int mx = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			mx = std::max(mx, a[i]);
		}
		std::string ans = "YES\n";
		
		for(int i = 0; i < n; i++) {
			if(mx == a[i]) {
				int j = i;
				while(j - 1 >= 0 && a[j] >= a[j - 1]) j--;
				
				if(j - 1 >= 0) {
					ans = "NO\n";
					break;
				}				

				j = i;
				while(j + 1 < n && a[j] >= a[j + 1]) j++;
				
				if(j + 1 < n) {
					ans = "NO\n";
				}
				break;
			}
		}
		
		std::cout << ans;
	}
	return 0;
}
```





## 要点

倒着思考，先思考最优解，然后尝试从最优解开始扩展。



# C. [Build Permutation](https://codeforces.com/problemset/problem/1713/C)

## 问题描述

给定整数n，要求构造一个从0到n-1的全排列a，满足：

1. a[i] + i 是一个完全平方数



如果不存在，输出-1



## 问题思路

先分析最大值的范围。显然，数组a的最大值是n-1，我们可以为它+0或者+(n-1)，因此最大值的范围在：

n-1 <= x <=  2 * (n-1)



注意到必然恰好有1个完全平方数，在  n-1 < k * k <= 2 * (n-1)，令n - 1 + h = k * k，则   0 <=   h <=  n - 1

所以可以找到一点 h 把 [0, n-1]分为2部分，[h, n - 1] 部分可以首位相加，满足题意。



至于[0, h-1]部分，把上面的结论再用一次直到处理完整个数组



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, n, a[100001];

void slv(int r) {
	if(r < 0) return;
	int s = sqrt(r*2); s = s * s;
	int l = s - r;
	slv(l-1);
	for(; l <= r; l++, r--) {
		a[l] = r;
		a[r] = l;
	}
} 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		slv(n-1);
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
```





## 要点

注意到 n <= (k+ 1) * (k + 1)  =  k * k + 2 * k + 1 <=  2  * k * k <= 2 * n，当 k >= 3时。