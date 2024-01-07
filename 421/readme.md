# A. [Pasha and Hamsters](https://codeforces.com/problemset/problem/421/A)

## 问题描述

给定整数n、长度n1的数组a和长度n2的数组b。



现在循环i，从1到n。如果i在a中存在，输出1，否则输出2.



## 问题思路

按照题目模拟即可。



判断是存在，可以使用数组来表示。



## 实现代码

```c++
#include<iostream>

int n, n1, n2;
bool has[101];
int main() {
	std::cin >> n >> n1 >> n2; 
	
	int x;
	for(int i = 0; i < n1; i++) {
		std::cin >> x;
		has[x] = true;
	}
	
	for(int i = 1; i <= n; i++) {
		if(has[i]) std::cout << "1 ";
		else std::cout << "2 ";
	}
	
	std::cout << "\n";
	return 0;
} 
```





## 要点

模拟