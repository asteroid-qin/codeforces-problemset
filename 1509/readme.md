# A. [Average Height](https://codeforces.com/problemset/problem/1509/A)

## 问题描述

给定长度n的数组a，要求重新排序使得，连续的算数平均值是整数的数量最大化。



## 问题思路

考虑什么情况下相邻的算数平均值是整数？

相邻都是偶数或者都是奇数。



所以可以对a分类，按照奇偶性。

然后把奇数放在连续的一起再把偶数放在连续的一起。



为了简单起见。可以循环两边数组，先放奇数再放偶数。



## 实现代码

```c++
#include<iostream>

int t, n, a[2000], b[2000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int p = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(a[i] & 1) b[p++] = a[i];
		}
		
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 == 0) {
				b[p++] = a[i];
			}
		}
		
		for(int i = 0; i < n; i++) {
			std::cout << b[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

意识到奇偶性，然后分类