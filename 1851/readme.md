# A. [Escalator Conversations](https://codeforces.com/problemset/problem/1851/A)

## 问题描述

给长度n整数数组a，给长度m整数数组b。数组a的值由输入给出，数组b的值由k解决：$$b_1=k \ 且 \ b_i = b_{i-1} + k$$。给定值H，循环数组a，如果a[i]-H的绝对值在k到(m-1)k之间且能被k整除，那么ans++， 最后输出ans。



## 问题思路

按照题目要求，循环数组a。



输出打印即可。



## 实现代码

```c++
#include<iostream>

int t, n, k, H, m;

void slv() {
	std::cin >> n >> m >> k >> H;
	
	int ans = 0, x;
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		x = abs(H - x);
		if(x % k == 0 && k <= x && x <= (m-1) * k) {
			ans++;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```





## 要点

读题（题干又臭又长）