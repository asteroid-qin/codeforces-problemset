# B. [Putting Plates](https://codeforces.com/problemset/problem/1530/B)

## 问题描述

给定n * m的二维数组a（初始全为0），可以在a边缘设置1，但要满足：1所在的八字格没有任何一个1.



现在求最多能放多少个1？

## 问题思路

注意到有最优解：四个角都设为1.然后从4个边开始+2设置'1'



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, n, m;
char mp[21][21];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				mp[i][j] = '0';
			}
		}		
		
		
		// 上 
		for(int i = 1; i <= m-2; i+=2) {
			mp[1][i] = '1';
		}	
		// 下 
		for(int i = 1; i <= m-2; i+=2) {
			mp[n][i] = '1';
		}
		
		// 左
		for(int i = 1; i <= n-2; i+=2) {
			mp[i][1] = '1';
		}	
		// 右 
		for(int i = 1; i <= n-2; i+=2) {
			mp[i][m] = '1';
		}
		mp[n][m] = '1';
		
		// out
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				std::cout << mp[i][j];
			}
			std::cout << "\n";
		}
		 
	}
	return 0;
} 
```





## 要点

贪心