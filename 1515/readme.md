# A. [Phoenix and Gold](https://codeforces.com/problemset/problem/1515/A)

## 问题描述

给定长度n的整数数组a，和整数x。要求重新排列a，满足：

从下标1开始累加，任意和都不等于x。



## 问题思路

如果x等于数组a的和，那么没有结果。

否则，x大于数组a的和？不需要排列。

否则，x小于数组a的和？



既然是小于，那么可能中途加上一个值导致等于x。而所有元素都是不同的且都大于0，所以相等的情况最多出现一次。

既然如此，那么我们可以排序：以升序。

一旦遇到当前和等于x，我们交换i与i+1的位置即可，使得当前和大于x，并以后都是大于x。



当然，实际思考后发现其实排序这一步并没有必要。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[100], x;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> x;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		
		if(sum < x) {
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << a[i] << " ";
			}
			std::cout << "\n";
			continue;
		}
		
		if(sum == x) {
			std::cout << "NO\n"; 
			continue;
		}
		
		std::sort(a, a+n);
		
		sum = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			if(sum == x && i + 1 < n) {
				sum += a[i+1] - a[i];
				std::swap(a[i], a[i+1]);
			}
		}
		
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

分类讨论