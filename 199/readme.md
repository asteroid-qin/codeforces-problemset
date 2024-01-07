# A. [Hexadecimal's theorem](https://codeforces.com/problemset/problem/199/A)

## 问题描述

给定一个斐波那契数x，判断它能否由3个斐波那契数的和表示。



## 问题思路

我们都知道斐波那契数是按照指数增长，因此在很短的时间里，就可以求出1-1e9的所有的斐波那契数组 a。



因为x也为斐波那契数，如果a[i] = x，那么显然输出 0 a[i-1]  a[i-2] 即可。



注意：由于上面需要i-2，所以当n=0或者1时，需要手动输出答案。



## 实现代码

```c++
#include<iostream>

int n, x, a[100];
int main() {
	n = 2;
	a[0] = 0, a[1] = 1;
	
	for(int i = 2; i <= 100; i++) {
		a[i] = a[i-1] + a[i-2];
		if(a[i] > 1e9) break;
		n++;
	}
	std::cin >> x;
	
	if(x == 0) {
		std::cout << "0 0 0\n";
		return 0;
	}
	
	if(x == 1) {
		std::cout << "0 0 1\n";
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] == x) {
			std::cout << 0 << " " << a[i-2] << " " << a[i-1] << "\n";
			return 0;
		}
	}
	std::cout << "-1\n";
	return 0;
}
```



## 要点

如果a[i] = x，那么： 0 a[i-1]  a[i-2] 是种方案