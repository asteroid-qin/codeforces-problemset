# A. [Far Relative’s Birthday Cake](https://codeforces.com/problemset/problem/629/A)

## 问题描述

给定n*n的矩阵a，如果：a[i] [j] = a[p] [q] =  'c' 且 （i == p 或者 j == q），则称a[i] [j] 与 a[p] [q]  构成了1对。



现在问，a中点对数量是？



## 问题思路

循环两遍：先循环行，统计i=p的点对，再循环列，统计j =q的点对，得到的和就是答案。



显然，我们有结论，如果当前行或者列有x个'c'，那么它的贡献是：x * (x - 1) / 2



剩下的，只需要循环计数即可。



## 实现代码

```c++
#include<iostream>

int n;
char a[101][101];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		int cnt = 0; 
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'C') cnt++;
		}
		
		ans += cnt * (cnt - 1) / 2;
	}
	
	for(int j = 0; j < n; j++) {
		int cnt = 0; 
		for(int i = 0; i < n; i++) {
			if(a[i][j] == 'C') cnt++;
		}
		
		ans += cnt * (cnt - 1) / 2;
	}
	
	std::cout << ans << "\n";
	return 0;
}
```



## 要点

排列组合