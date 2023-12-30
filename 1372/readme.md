# A. [Omkar and Completion](https://codeforces.com/contest/1372/problem/A)

## 问题描述

给定整数n，要求构造长度n的数组a，满足：

1. 数组a中任意两个数的和在数组a中不存在



## 问题思路

注意到可以令所有元素都相等。假如这个值是k，因为 k 不等于 2 k，所以是满足的。



不妨令k是1，如此有：

输出 n 个1



## 实现代码

```c++
#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
	
		for(int i = 1; i <= n; i++) std::cout << "1 ";
		std::cout <<  "\n";
	}
	return 0;
}
```



## 要点

试着让所有元素都相等