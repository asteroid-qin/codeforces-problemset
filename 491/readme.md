# A. [Up the hill](https://codeforces.com/problemset/problem/491/A)

## 问题描述

给定整数a和b，满足a+b+1=n。现在要求输出1个1-n的全排列a，满足：先是a个递增，后是b个递减。



## 问题思路

先递增后递减，因此中间元素是数组的最大值 n。

可以先输出a个元素：从1开始，a结束。

再输出1个元素：n。

如此便完成了第一个要求：先是a个递增。



最后倒着输出b个元素：从n-1开始，n-b结束。

如此便完成了第一个要求：先是b个递减。



显然，a[i] 每个元素都不同，正是1-n的一个全排列。因此这种构造方法是可行的。



## 实现代码

```c++
#include<iostream>

int n, a, b;

int main() {
	std::cin >> a >> b;
	int n = a + b + 1; 

	for(int i = 1; i <= a; i++) {
		std::cout << i << " ";
	}
	
	std::cout << n << " ";
	
	for(int i = n - 1; b > 0; i--, b--) {
		std::cout << i << " ";
	}
	
	std::cout << "\n";
}
```



## 要点

先增后减，中间元素必然是数组的最大值：n