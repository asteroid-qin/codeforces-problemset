# A. [Pretty Permutations](https://codeforces.com/problemset/problem/1541/A)

## 问题描述

给定n，输出一个1-n的全排列p。满足 i != p[i] 且 abs(i-p[i]) 的和最小。



## 问题思路

n=4

2 1  4 3: 最小值n



显然，偶数的话只要交换相邻的元素即可



n=5

3 1 2 5 4 ：最小值n+1

n=7

1 2 3 4 5 6 7

3 1 2 5 4 7 6

显然，奇数总是以3 1 2开头，后续继续交换相邻的元素即可。



## 实现代码

```c++
#include<iostream>

int n, t;

void slv() {
	std::cin >> n;
	if(n&1) {
		std::cout << "3 1 2 ";
		for(int i = 4; i <= n; i += 2) {
			std::cout << i + 1 << " " << i << " ";
		}
		std::cout << "\n";
		return;
	}
	
	for(int i = 1, p = 1; i <= n; i += 2, p++) {
		std::cout << p * 2 << " " << p * 2 - 1 << " ";
	}
	std::cout << "\n";
}

int main () {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点

意识到交换相邻2元素。