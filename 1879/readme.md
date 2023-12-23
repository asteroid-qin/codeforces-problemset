# B. [Chips on the Board](https://codeforces.com/problemset/problem/1879/B)

## 问题描述

给n×n的数组（初始为0），将i,j处设为1的花费为row[i] + col[j]。现在求让每个i，j所在行或者列都有一个1的最小花费是多少。



## 问题思路

复用kruskal算法的思路，把n*n的点加入，权值是此点的row[i]+ col[j]。

每次找最小的权值，但是这并不是最优。因为可能存在一个权值比较小的点只能覆盖row，col重复了，导致后面还得找个col，而这个可能会被后面一个权值较大且能够覆盖row和col的点给优化。



把问题降维，假如只有一个数组，那么显然是这个数组的最小值。尝试把结论推广到二维，发现固定着row，每列的值都是一样的。

我们固定最小的row[i]，开始选择col[j]。



总之，有两种可能：

1. 选择最小的行对列求和

2. 选择最小的列对行求和



## 实现代码

```c++
#include<iostream>


int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int a, b;
		long long sum_row = 0, sum_col = 0;
		int min_row = 1e9, min_col = 1e9;
		 
		for(int i = 0; i < n; i++) {
			std::cin >> a;
			sum_row += a;
			min_row = std::min(min_row, a);
		}
		
		for(int i = 0; i < n; i++) {
			std::cin >> b;
			sum_col += b;
			min_col = std::min(min_col, b);
		}
		
		std::cout << std::min(sum_row + (long long)n * min_col ,  sum_col + (long long) n * min_row  ) << "\n";
	}
	
	return 0;
}
```





## 要点

问题做减法