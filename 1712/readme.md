# B. [Woeful Permutation](https://codeforces.com/problemset/problem/1712/B)

## 问题描述

要求构造一个长度n的1-n的全排列，使得lcm(i, pi)的和尽可能大。



## 问题思路

lcm(a,b) = a*b/gcd(a,b)，既然a和b是给定的，那么应该尽可能让gcd(a,b)最小。



这里猜想是n, 1, 2, ..., n-1。因为i与pi互质。

但是这并不代码和是最大。可以计算出这种模式的和是 i*(i-1)和+n，i > 1



如果是1, 2, 3, .., n，和则是n*(n+1)/2。



奇数从1开始，偶数从2开始。



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int p = 0;
		if(n & 1) {
			std::cout << 1 << " ";
			n--;
			p = 1;
		}
		
		for(int i = 1; i <= n; i += 2) {
			int x = 2 * ( (i / 2) + 1) + p;
			std::cout << x << " " <<  x - 1 << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

... 很难证明。