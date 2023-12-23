# A. [Anti-knapsack](https://codeforces.com/problemset/problem/1493/A)

## 问题描述

给定整数n和k，要求选出1到n中所有的整数，它们满足：子集的和不等于k。



要求选出的整数的数量最大。

## 问题思路

对1-n的所有数分类讨论：



1. 首先比k大的显然都是可选的。

2. 等于k不能选。

3. 小于k。可以选k-1，但是不选1，可以选k-2，但是不选2....也就是可以选择k-m，但是不能选择m。满足k-m >=m => m*2 <= k。



综上：

把k+1到n的数和k-i的数 ( i*2 <= k) 作为结果.



## 实现代码

```c++
#include<iostream>

int t, a[1001], n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		int p = 0;
		for(int i = k + 1; i <= n; i++) {
			a[p++] = i;
		}
		
		for(int i = 1; i * 2 <= k; i++) {
			a[p++] = k - i;
		} 
		
		std::cout << p << "\n";
		for(int i = 0; i < p; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

分类