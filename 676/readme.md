# A. [Nicholas and Permutation](https://codeforces.com/problemset/problem/676/A)

## 问题描述

给定1-n的全排列a，要求交换两个元素，使得1与n的距离差最大。



## 问题思路

不妨设1在n的坐标，即a[1] < a[n]。

要让a[n] - a[1]的值最大，显然有2种可能：

1. n移到最右端
2. 1移到最左端

只要求两种的最大值即可。



总结：

记录p=min(a[1],a[n]), q = max(a[1], a[n])，输出max(n - p, q - 1)

## 实现代码

```c++
#include<iostream>

int n, a[101];
int main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		a[x] = i;
	}
	
	int p = std::min(a[1], a[n]);
	int q = std::max(a[1], a[n]);
	
	std::cout << std::max(n - p, q - 1) << "\n";
	return 0;
}
```



## 要点

分类讨论