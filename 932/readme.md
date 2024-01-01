# A. [Palindromic Supersequence](https://codeforces.com/problemset/problem/932/A)

## 问题描述

给定字符串s，要求找到一个t，满足：

1. s是t的子序列
2. t是回文串



## 问题思路

注意到，t的长度要求是s的10倍，因此可以把s翻转一次，得到长度为2 |s| 的回文串



总结：

输出s和逆序后的s



## 实现代码

```c++
#include<iostream>

std::string s;
int main() {
	std::cin >> s;
	int n = s.size();
	
	std::cout << s;

	for(int i = n-1; i >= 0; i--) std::cout << s[i];
	std::cout << "\n";
	
	return 0;
} 
```



## 要点

翻转