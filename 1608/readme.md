# A. [Find Array](https://codeforces.com/problemset/problem/1608/A)

## 问题描述

给定n，构造长度n的整数数组a，满足：

1. 1 <= ai <= 1e9
2. ai < ai+1
3. ai 不被ai-1整除



## 问题思路

不被整除很简单，只要每次加一即可同时把递增也解决了。



综上：打印2到n+1



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << i + 1 << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

a不被a-1整除