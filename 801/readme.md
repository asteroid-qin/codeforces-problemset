# B. [Valued Keys](https://codeforces.com/problemset/problem/801/B)

## 问题描述

给定长度为n的字符串x和y，如果存在y中1个字符比x中对位的字符要大，那么输出-1，否则输出y。



## 问题思路

按照题目要求模拟即可



## 实现代码

```c++
#include<iostream>

std::string x, y;
int main() {
	std::cin >> x >> y;
	int n = x.size();
	for(int i = 0; i < n; i++) {
		if(x[i] < y[i]) {
			std::cout << "-1\n";
			return 0;
		}
	}
	std::cout << y << "\n";
	return 0;
} 
```



## 要点

读题