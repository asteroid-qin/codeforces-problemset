# C. [Not Adjacent Matrix](https://codeforces.com/problemset/problem/1520/C)

## 问题描述

给定n，要求构造一个n * n 的二维数组，满足：

1. 1到n*n中每个数在数组中恰好出现一次
2. 相邻元素的差的绝对值不能是1



## 问题思路

考虑n=1，很轻松

考虑n=2：找不到

考虑n=3：

2 9 7 1
4 6 3 1
1 8 5 1

1 1 1 1



尝试先放1，显然1需要尽可能的接触多的边因为他只与2相邻.

而2可以放在1的斜角处，保证不相邻。



发现规律：斜着从大到小放值。

但是如何证明满足要求呢？

先放1到n在对角线，划出一条分割线。在两边斜角分别斜着递增即可。

显然是满足题意的。



## 实现代码

```c++
#include<iostream>

int t, n, a[101][101]; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n == 1) {
			std::cout << "1\n";
			continue;
		}
		if(n == 2) {
			std::cout << "-1\n";
			continue;
		}
		
		// 设置中线
		for(int i = 1; i <= n; i++) {
			a[i][i] = i;
		} 
		
		int st = n + 1, ed = n * n, k = 2;
		while(k <= n) {
			// 先左下角			
			int x = k, y = 1;
			while(x <= n) {
				a[x][y] = st;
				st++;
				x++;
				y++;
			}
			
			// 再右下角 
			x = 1, y = k;
			while(y <= n) {
				a[x][y] = st;
				st++;
				x++;
				y++;
			}
			
			k++;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				std::cout << a[i][j]  << " ";
			}
			
			std::cout << "\n";
		}
	}
	return 0;
}
```



## 要点

纯思路