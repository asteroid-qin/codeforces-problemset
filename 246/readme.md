# A. [Buggy Sorting](https://codeforces.com/problemset/problem/246/A)

## 问题描述

给定一个冒泡排序算法（错误的），和一个整数n。要求构造1个长度n的整数数组a，可以hack这个算法。



## 问题思路

显然，只需要构造1个n到1的倒序数组就可以满足题意。



因此：

如果n>2，循环i，从n到1，输出i。

否则，输出-1



## 实现代码

```c++
#include<iostream>

int n;
int main() {
	std::cin >> n;
	if(n > 2) {
		for(int i = n; i >= 1; i--) {
			std::cout << i << " ";
		}
	} else {
		std::cout << "-1";
	}
	
	std::cout << "\n";
	return 0;
}
```



## 要点

n到1的数组就可以满足要求