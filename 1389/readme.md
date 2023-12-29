# A. [LCM Problem](https://codeforces.com/problemset/problem/1389/A)

## 问题描述

给定正数l和r且l < r。要求构造正数x和y，满足：

1. l <= x < y <= r
2. l <= LCM(x, y) <= r



## 问题思路

证明 + 贪心



因为LCM(x, y) = x * y / gcd(x, y)，而 y >= gcd(x, y)

所以 x * y / gcd(x, y) >= x 即 LCM(x, y) > x. 



令g = gcd(x, y)，所以 x = q * g, y = p * g，gcd(p, q) = 1，

又因为 LCM(x, y) = q * p * g  = x * p > x

所以 p > 1，所以p最小取2，即 x * p >= 2 * x => LCM(x, y) >= 2 * x。



最关键的部分在于：LCM(x, y) >= 2 * x。

要使得满足题意，所以LCM(x, y) 要尽可能小，也就是等于2 * x。



可以让y=2x，这样LCM(x, y)最小，且y也最小。



最后贪心地也让x最小，也就是：x = L。



因此，有：x = L, y = 2 * L。



## 实现代码

```c++
#include<iostream>

int t, l, r;
void slv() {
	std::cin >> l >> r;
	
	if(l * 2 > r) {
		std::cout << "-1 -1\n";
		return;	
	}		
	std::cout << l << " " << l * 2 << "\n";
}

int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
}
```



## 要点

证明: LCM(x, y) >= 2 * x （当x < y 时)  贪心