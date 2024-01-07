# A. [Table](https://codeforces.com/problemset/problem/359/A)

## 问题描述

给定n行m列的矩阵a，a[i] [j] 的值要么为1要么为0。可以执行一次操作：

1. 选择a[i] [j] = 1的单元格，再选择任意4个角落中的一个a[p] [q]，将a[x] [y] = 2。x满足：  min(i, p) <= x <= max(i, p)，y满足：min(j, q) <= y <= max(j , q)。



现在保证4个角落的值都是0，现在问让a的值全为2的最小操作数。



## 问题思路

对a[i] [j] = 1的点分类讨论：



如果在角落，不符合题意，舍去

如果在边上，只需要2次就可以完成任务

如果在中间，需要4次



因此，循环四条边，只要有1个值是1，那么输出2。否则输出4。



## 实现代码

```c++
#include<iostream>

int n, m, a[51][51];

int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	
	bool has = false;
	for(int i = 0; i < n; i++) {
		has |= a[i][0] == 1 || a[i][m-1] == 1;
	}
	
	for(int i = 0; i < m; i++) {
		has |= a[0][i] == 1 || a[n-1][i] == 1;
	}
	
	if(has) std::cout << "2\n";
	else std::cout << "4\n";
	
	return 0;
}
```



## 要点

对a[i] [j] = 1的i和j的位置分类讨论