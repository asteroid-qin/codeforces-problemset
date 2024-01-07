# B. [Preparing for the Contest](https://codeforces.com/problemset/problem/1914/B)

## 问题描述

给定整数n和k，要求构造一个1-n的全排列a，满足：

1. a[i]  > a[i-1]的i的个数等于k



## 问题思路

显然：

如果k=n-1，那么a必然是 1 2 3 4 ... n-3 n-2 n-1 n

如果k=n-2，那么a可以是 1 2 3 4 ... n-3 n-2 n n-1 

如果k=n-3，那么a可以是 1 2 3 4 ... n-3 n n-1  n-2 

...

如果k=0，那么a可以是 n n-1 n-2 n-3 ... 4 3 2 1



显然这是有规律的，我们只需要：

输出1到k，再倒着输出n到(k+1)，即可



## 实现代码

```c++
#include<iostream>

int t, n, k;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		for(int i = 1; i <= k; i++) {
			std::cout << i << " ";
		}
		for(int i = n; i >= k+1; i--) {
			std::cout << i << " ";
		}
		
		std::cout << "\n";
	}
	
	return 0;
} 
```



## 要点

找规律