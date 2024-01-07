# A. [Levko and Table](https://codeforces.com/problemset/problem/361/A)

## 问题描述

给定整数n和k，要求构造一个n行n列的矩阵a，满足：

1. 每行的和等于k
2. 每列的和等于k
3. -1000 <= a[i] [j] <= 1000



## 问题思路

显然，只需要对角线的值设为k，其他全是0即可。



这种构造的正确性不难证明。



因此，可以双层循环i、j。i和j都是[1, n]

当i=j时，输出k，否则输出0。



## 实现代码

```c++
#include<iostream>

int n, k;
int main() {
	std::cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) std::cout << k << " ";
			else std::cout << "0 ";
		}
		
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

对角线