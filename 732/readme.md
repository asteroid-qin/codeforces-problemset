# A. [Buy a Shovel](https://codeforces.com/problemset/problem/732/A)

## 问题描述

给定整数k和r（1<=r<=9)，求找到一个数p。

定义：a=k*p。



现在要找最少的p，使：a%10=r或者a%10=0



## 问题思路

注意到：

k = 10b1 + r1 （b1、r1都是整数，0 <= r1 < 10)

p = 10b2 + r2（b2、r2都是整数，0 <= r2 < 10)

所以：

a = k * p = 100 * b1* b2+10 * b1 * r2+10 * b2 * r1 + r1 * r2

所以 a %10 = (r1*r2)%10 = r



注意这里只与余数有关，所以我们可以令b2=0，暴力循环r2，来选择满足条件的最小p。

再由题意（p不能为0），得到p的循环范围在[1, 10]，只需要找出最小的满足要求的p即可。



总结：

循环i，从1到10，如果(i*k)%10=r 或者 =0，那么输出答案i。



## 实现代码

```c++
#include<iostream>

int k, r;
int main() {
	std::cin >> k >> r;
	for(int i = 1; i <= 10; i++) {
		int x = i * k % 10;
		if(x == r || x == 0) {
			std::cout << i << "\n";
			return 0;
		}
	}
	return 0;
} 
```



## 要点

利用数论得到只和余数有关，将需要遍历的数据范围缩减到[1, 10]