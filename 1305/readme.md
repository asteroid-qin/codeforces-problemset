# A. [Kuroni and the Gifts](https://codeforces.com/problemset/problem/1305/A)

## 问题描述

给定长度n的两两不同的整数数组a和b，要求重新排列a和b，使得ai+bi两两不同



## 问题思路

说起排序就想到升序或者降序，不妨让a和b升序排列然后注意到一个性质：



对ai、aj、bi、bj （i < j)，因为升序排序后 ai < aj，bi < bj，所以ai + bi < aj + bj。

也就是ai+bi严格单调递增，所以两两不同。



总结：

输出升序排列后的a和b。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[100], b[100];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin  >> n;
		for(int i = 0; i < n; i++) std::cin>> a[i];
		for(int i = 0; i < n; i++) std::cin>> b[i];
		
		std::sort(a, a+n);
		std::sort(b, b+n);
		
		for(int i = 0; i < n; i++) std::cout << a[i] << " ";
		std::cout << "\n";
		for(int i = 0; i < n; i++) std::cout << b[i] << " ";
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

严格单调递增意味着两两不同

