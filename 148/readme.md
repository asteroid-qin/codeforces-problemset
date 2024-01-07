# A. [Hexadecimal's theorem](https://codeforces.com/problemset/problem/199/A)

## 问题描述

给定整数d和长度4的整数数组a，要求循环i，从1到d，求满足下面条件的i个数：

1. 存在a[j]使得：i % a[j] = 0



## 问题思路

因为 d < 1e5，所以直接模拟即可。



## 实现代码

```c++
#include<iostream>

int n, a[4], d;
int main() {
	n = 4;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	std::cin >> d;
	
	int ans = 0;
	
	for(int i = 1; i <= d; i++) {
		for(int j = 0; j < n; j++) {
			if(i % a[j] == 0) {
				ans++;
				break;
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}
```



## 要点

模拟