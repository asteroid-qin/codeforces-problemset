# B. [Madoka and the Elegant Gift](https://codeforces.com/problemset/problem/1647/B)

## 问题描述

又臭又长....



总之要求每个含1的连通块矩阵，不能存在凸起



## 问题思路

既然是矩阵的突起，那么肯定会有块 2 * 2 的单元格里面会有3个'1'和1个'0'



因此只需要循环整个矩阵，判断是否存在某个2 * 2的单元格，里面'1'出现的次数等于3即可



## 实现代码

```c++
#include<iostream>

int t, n, m;
char a[100][100];

int check(int x, int y) {
	int cnt = a[x][y] == '1';
	cnt += a[x+1][y+1] == '1';
	cnt += a[x][y+1] == '1';
	cnt += a[x+1][y] == '1';
	return cnt;
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cin >> a[i][j];
			}
		}
		
		bool ok = true;
		for(int i = 0; i < n-1 && ok; i++) {
			for(int j = 0; j < m-1; j++) {
				if(check(i, j) == 3) {
					ok = false;
					break;
				}
			}
		}
		
		if(ok) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
```



## 要点

读题