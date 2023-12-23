# A. [Mean Inequality](https://codeforces.com/problemset/problem/1526/A)

## 问题描述

给2*n个整数，要求重新排列，满足：

1. 任意一个数不是左右邻居的算术平均数。
2. 对于第一个它的左邻居是最后一个元素，最后一个的右邻居是第一个元素。



## 问题思路

先排序保证：a1 < a2 < ... < an



n=2时，有：

a < b < c <d

c a d c  : 显然相邻的元素的平均数要么大于，要么小于



n=3时，有：

a < b < c < e < f < g

e a f b g c：依旧满足。

a e b f c g: 依旧满足



猜想：排序后，循环i从1到n，输出a[i] a[i+n]

## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[60];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n*2; i++) {
			std::cin >> a[i]; 
		}
		std::sort(a+1, a+1+n*2);
		
		for(int i = 1; i <= n; i++) {
			std::cout << a[i] << " " << a[i+n] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```





## 要点

排序

