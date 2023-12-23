# B. [Bad Boy](https://codeforces.com/problemset/problem/1537/B)

## 问题描述

给定n * m 的二维数组，和坐标（x，y）。求输出两点，使得走过两点再回去的距离最大。



## 问题思路

如果只有一个点，显然这个点是四个角离x，y最远的距离。



而离这个点最远的角便是这个的对角。



突然意识到对顶角就是最远的。



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, n, m, i, j;

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m >> i >> j;
		std::cout << 1 << " " << 1 << " " << n << " " << m << "\n";
	}
	return 0;
} 
```





## 要点

贪心