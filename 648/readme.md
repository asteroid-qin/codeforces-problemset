# A. [Наибольший подъем](https://codeforces.com/problemset/problem/648/A)

## 问题描述

给定n*m的字符矩阵a，需要将它映射为1个长度m个整数数组b：b[i]的值是矩阵第i列的 * 的个数。



现在问：b[i] - b[i-1]的最大值和b[i-1]-b[i]的最大值



## 问题思路

读完题目，直接照着意思模拟即可



## 实现代码

```c++
#include<iostream>

int n, m;
char a[100][100];
int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	
	int pre = 0;
	for(int j = 0; j < n; j++) {
		if(a[j][0] == '*') pre++;
	}
	
	int x = 0, y = 0;
	for(int i = 1; i < m; i++) {
		int cur = 0;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == '*') cur++;
		}
		
		x = std::max(x, cur - pre);
		y = std::max(y, pre - cur);
		pre = cur;
	}
	
	std::cout << x << " " << y << "\n";
	
	return 0;
}
```





## 要点

模拟



# B. [Собери стол](https://codeforces.com/problemset/problem/648/B)

## 问题描述

给定长度n*2的整数数组a，要求将其两两分组：得到n组，且n个组的和都相等。



## 问题思路

因为n个组的和都相等，假设数组a的和是sum，则每组的和都是k= sum / n。



因此可以双重循环数组a，外层是i，i在[1, n]。

内层先用全局数组判断i是否已经被访问，被访问过则跳过，否则标记被访问并进入内层循环：

内层是j，j在[1, n]，需要找到一个没被访问的j且a[j]+a[i] = k，按照题意，总能找到一个满足要求的j，然后标记j被访问即可。



## 实现代码

```c++
#include<iostream>

int n, a[2000];
bool vis[2000];
int main() {
	std::cin >> n;
	n *= 2;
	
	int sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	
	int k = sum * 2 / n;
	
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		
		for(int j = 0; j < n; j++) {
			if(vis[j] || a[i] + a[j] != k) continue;
			
			vis[j] = true;
			
			std::cout << a[i] << " " << a[j] << "\n";
			break;
		}
	}
	return 0;
}
```





## 要点

模拟