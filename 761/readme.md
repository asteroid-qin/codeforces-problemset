# A. [Dasha and Stairs](https://codeforces.com/problemset/problem/761/A)

## 问题描述

给定整数a和b，判断是否存在从l到r（1 <= l <= r)满足：[l, r] 中有a个奇数和b个偶数。



## 问题思路

先对l分类讨论：

如果l是奇数，那么显然如论r取多少，奇数出现的次数总是 >= 偶数出现的次数，且最多只能大于1。

如果l是偶数，那么显然如论r取多少，偶数出现的次数总是 >= 奇数出现的次数，且最多只能大于1。



因为，a和b的绝对值必须 <= 1。否则输出false



注意数据范围！a和b可能取到0，又因为l >= 1，所以至少能取到1个奇数或者偶数，因此a+b必须>0。

## 实现代码

```c++
#include<iostream>

int a, b;
int main() {
	std::cin >> a >> b;
	if(abs(a-b) <= 1 && a + b > 0) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
}
```





## 要点

分类讨论