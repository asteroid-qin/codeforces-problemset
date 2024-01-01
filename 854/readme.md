# A. [Fraction](https://codeforces.com/problemset/problem/854/A)

## 问题描述

给定整数n，要求输出整数a、b，满足：

1. a+b=n
2. a / b 尽可能最大
3. a < b
4. a与b互质



## 问题思路

因为n的数据范围在1000，因此倒着枚举a，从(n-1)/2到1，选出满足条件的第一个a即可



## 实现代码

```c++
#include<iostream>

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	int n;
	std::cin >> n;
	for(int i = (n-1) / 2; i >= 1; i--) {
		int j = n - i;
		if( i < j && gcd(i, j) == 1) {
			std::cout << i << " " << j << "\n";
			return 0;
		}
	} 
	
	return 0;
}
```



## 要点

暴力