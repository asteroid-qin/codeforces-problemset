# A. [Vitaly and Night](https://codeforces.com/problemset/problem/595/A)

## 问题描述

给定n个测试用例。每个用例中，给定整数m和长度是2 * m的整数数组a，要求对于每个i （1 <= i <= m)，求出a[i*2-1]+a[i * 2]>0的个数。



最后输出n个测试用例的个数的和



## 问题思路

模拟即可



## 实现代码

```c++
#include<iostream>

int n, m, a[202];
int main() {
	std::cin >> n >> m;
	
	int ans = 0;
	while(n--) {
		for(int i = 1; i <= m*2; i++) {
			std::cin >> a[i];
		}
		
		for(int i = 1; i <= m; i++) {
			if(a[i*2-1] + a[i*2] > 0) ans++;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}

```



## 要点

审题