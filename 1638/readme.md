# A. [Reverse](https://codeforces.com/problemset/problem/1638/A)

## 问题描述

给定1-n的全排列，执行一步操作，使得新的排列的字母顺序最小。操作指的是：翻转一段连续的区间。



## 问题思路

要最小，显然得把最小值放在最前面。



循环找i != p[i]的，找不到就反转[1,1]。



找到了就反转 [i, p[i]=i的索引]



最后输出即可

## 实现代码

```c++
#include<iostream>

int t, n, idx[501], a[501];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int dif = -1;
		
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			idx[a[i]] = i;
			if(dif == -1 && a[i] != i) {
				dif = i;
			}
		}
		
		int l, r;
		if(dif == -1) {
			l = 1;
			r = 1;
		}  else {
			l = dif;
			r = idx[dif];
		}
		
		while(l < r) std::swap(a[l++], a[r--]);
		
		for(int i = 1; i <= n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

贪心