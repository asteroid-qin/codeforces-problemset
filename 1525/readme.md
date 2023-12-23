# B. [Permutation Sort](https://codeforces.com/problemset/problem/1525/B)

## 问题描述

给1-n的全排列数组a，可以执行一次操作：选择任意长度小于n的连续子数组排序。

现在问，使得a升序的最小操作数。

## 问题思路

如果a是升序，答案就是0.

否则判断1在a的头部或者n在a的尾部，答案是1.

其他就是2了。

但是有没有可能是3呢？答案是有的：1放在末尾同时n放在头。

## 实现代码

```c++
#include<iostream>
#include<algorithm>
int t, n, a[51];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		bool fa = true;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			fa &= a[i] == i;
		}

		if(fa) {
			std::cout << "0\n";
			continue;
		}
		
		if(a[1] == 1 || a[n] == n) {
			std::cout << "1\n";
			continue;
		}
		if(a[1] == n && a[n] == 1) {
			std::cout << "3\n";
			continue;
		}
		std::cout << "2\n";
	}
	return 0;
} 
```



## 要点

贪心，发现只有0、1、2、3四种可能，再分类讨论。