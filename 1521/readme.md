# A. [Nastia and Nearly Good Numbers](https://codeforces.com/problemset/problem/1521/A)

## 问题描述

给定正整数a，b。找到三个不同的正整数：x，y，z。满足：

x+y=z 且

恰好有一个被a * b 整除，另外两个只被a整除。

## 问题思路

能被a * b整除，且x+y=z，因此得把z定义为被a*b整除的x、y、z中的最大值。



可以让z = a* b，

这样x = a，y = (b-1) * a 即可。



但是还得考虑a和b的范围。假如b=1，那么如论如何都找不到x、y、z满足条件的。

假如b=2，那么让x、y、z分别为：1a 3a 4a。



b >= 3的话，就是：a 	(b-1)*a	a *  b



注意！a、b的范围！

## 实现代码

```c++
#include<iostream>

long long a, b, t;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		
		
		if(b == 1) {
			std::cout << "NO\n";
			continue;
		} 

		std::cout << "YES\n";
		
		if(b == 2) {
			std::cout << a << " " << a*3 << " " << a*4 << "\n";
			continue;
		} 
		
		long long x = a, y = (b-1)*a, z = a*b;
		std::cout << x << " " << y << " " << z << "\n";
	}
	return 0;
}
```



## 要点

分类讨论 数论