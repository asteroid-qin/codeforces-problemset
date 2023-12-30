# B. [Bogosort](https://codeforces.com/problemset/problem/1312/B)

## 问题描述

给定长度n的整数数组a，要求输出重新排序后的a，满足：

1. 对于任意i、j（i < j），j - aj 不等于 i - ai



## 问题思路

要满足 j - aj 不等于 i - ai，也就是满足：j-i 不等于 aj-ai



注意到j > i，因此j-i都是大于0的，因此只要让aj-ai都小于0即可，也就是aj < ai



总结：输出倒序排列后的数组a（因为题目中ai是小于100的，所以可以使用计数排序）



## 实现代码

```c++
#include<iostream>

int t, n, a[101];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= 100; i++) a[i] = 0;
		for(int i = 0; i < n; i++) {
			int x; std::cin >> x;
			a[x]++;
		}		
		
		for(int i = 100; i >= 1; i--) {
			while(a[i]--) std::cout << i << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

移项得到：j-i 不等于 aj-ai，再转换为 aj < ai （当i < j）

