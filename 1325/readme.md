# A. [EhAb AnD gCd](https://codeforces.com/problemset/problem/1325/A)

## 问题描述

给定整数x，要求构造2个整数a和b，满足：

1. GCD(a,b) + LCM(a, b)  = x



## 问题思路

为了让问题变得简单，不妨令a=1，于是有：

GCD(1,b)+LCM(1,b)=1+b=x => b=x-1



结论显而易见：输出 1 x-1 即可

## 实现代码

```c++
#include<iostream>

int t, x;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> x;
		
		std::cout << 1 << " " << x - 1 << "\n";
		
	}
	return 0;
} 
```



## 要点

尝试带入1