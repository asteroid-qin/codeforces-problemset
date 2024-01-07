# A. [Game](https://codeforces.com/problemset/problem/513/A)

## 问题描述

给定整数n1和n2，输出最大值（n1是，输出：First，n2是，输出：Second）



如果n1=n2，那么输出：Second



## 问题思路

模拟即可



## 实现代码

```c++
#include<iostream>

int n1, n2, k1, k2;
int main() {
	std::cin >> n1 >> n2 >> k1 >> k2;
	if(n2 >= n1) {
		std::cout << "Second\n";	
	} else {
		std::cout << "First\n";	
	}
	
	return 0;
} 
```



## 要点

审题