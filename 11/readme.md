# A. [Increasing Sequence](https://codeforces.com/problemset/problem/11/A)

## 问题描述

给定长度n的整数数组a，和整数d。可以执行一次操作：

1. 选择b的一个元素，然后把它+d



求，使得a变为一个严格单调递增的最小操作数



## 问题思路

可以循环i，i从1到n-1，如果a[i] <= a[i-1]，那么：

令x = a[i-1]-a[i]，cnt =  x / d + 1

显然a[i]需要执行cnt次+d操作，才能大于a[i]



同时，答案便是 cnt 的和



## 实现代码

```c++
#include<iostream>

int n, d, a[2000];
int main() {
	std::cin >> n >> d;
	for(int i = 0; i < n; i++)  std::cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] <= a[i-1]) {
			int cnt = (a[i-1] - a[i]) / d + 1;
			
			ans += cnt;
			a[i] += cnt * d;
		}
	}	

	std::cout << ans << "\n";
	return 0;
}
```





## 要点

对于a[i]，最小的次数是：cnt =  (a[i-1]-a[i]) / d + 1，答案是cnt的和