# A. [Stable Arrangement of Rooks](https://codeforces.com/problemset/problem/1621/A)

## 问题描述

n*n的网格放k个车，定义如果没有2个车在同一行或者同一列则这个布置是**好的**。在好的布置之下，移动车到相邻的单元格导致不好，称为**不稳定的**,反之就是**稳定的**。



现在给定n和k，要求构造一种布置是稳定的。

## 问题思路

k=1怎么放都行。

k=2，最好放在左下和右上。



考虑k个到底该怎么放：

先放第一个，不妨放在左上角 1，1。

放第二个，想象下它可以在左上角往右或者往下挪动，所以只能放在 3，3

放第三个，同上只能放在5，5



...



总上，n个里面放k，需要满足：2k-1 <= n    =>   k <= (n+1) / 2



## 实现代码

```c++
#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(k > (n + 1) / 2) {
			std::cout << "-1\n";
			continue;
		}
		
        int p = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == p*2-1 && j == p*2-1 && p <= k) {
					std::cout << "R";
                    p++;
				} else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}
	return 0;
} 
```





## 要点

从左上角开始一个个放