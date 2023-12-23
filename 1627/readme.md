# A. [Not Shading](https://codeforces.com/problemset/problem/1627/A)

## 问题描述

有n*m的二维数组a，a的元素要么是0要么是1。现在可以执行一次操作：选中一个1把它所在的一行或者一列变为1。求坐标r，c列变为1的最小操作数。



## 问题思路

只要有一个1，那么绝对可以把全屏幕填充1.

对于任意r，c最多只需要2步就可以变为1。

1步的情况：只要这一行或这一列是1即可。



用row和col数组分别记录行或则和列存在1即可。



## 实现代码

```c++
#include<iostream>

int t, n, m, r, c;
char a[51][51];

int slv() {
	std::cin >> n >> m >> r >> c;
	bool f = true;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		std::cin >> a[i][j];
		if(a[i][j]=='B') f = false;
	 } 
	 
	if(f) {
		return -1;
	}
	r--; c--;
	if(a[r][c] == 'B') {
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i][c] == 'B') {
			return 1;
		}
	}
	
	for(int i = 0; i < m; i++) {
		if(a[r][i] == 'B') {
			return 1;
		}
	}
	return 2;
} 
int main() {
	std::cin >> t;
	while(t--) {
		std::cout << slv() << "\n";
	}
	return 0;
}
```





## 要点

意识到最小操作是2，剩下分类讨论