# A. [Three Piles of Candies](https://codeforces.com/problemset/problem/1196/A)

## 问题描述

输入a,b,c，求和/2



## 问题思路

读完题目，模拟即可



注意数据范围！

## 实现代码

```c++
#include<iostream>

int t;
int main() {
	std::cin >> t;
	long long a, b, c;
	while(t--) {
		std::cin >> a >> b >> c;
		std::cout << (a + b + c) / 2 << "\n";
	}
	return 0;
} 
```



## 要点

审题