# A. [K-divisible Sum](https://codeforces.com/problemset/problem/1476/A)

## 问题描述

给定n和k，要求构造长度n的正整数数组，它的和必须被k整除且最大值最小。



## 问题思路

n个数，最大值最小，显然尽可能让n个数都相等，这样增长的最慢，得到的最大值也会最小。



考虑最简单情况：n能被k整除。这里的最大值可以是1，因为它们的和是n。



继续讨论：n > k

因为最小值是1，所以和必然超过k。考虑到n=bk+r（b是正整数且r小于k），我们只需要让数组的和增加个k-r即可，这样和就是(b+1)k，能被k整除。而无论是k还是k-r都是小于n的，只需要把数组的k-r个1变为2即可。因此，答案是2。



考虑：n < k，

此时可以让所有值都是 k / n。如果k 不被 n整除，答案就是k / n + 1.



综上，分类讨论即可。

## 实现代码

```c++
#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(n % k ==0) {
			std::cout << "1\n";
			continue;
		}
		
		int ans;
		if(n < k) {
			ans = k / n; 
			if(k % n != 0) ans++;
		} else {
			ans = 2;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
} 
```



## 要点

尽量让所有值相等 对n和k分类