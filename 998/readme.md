# A. [Balloons](https://codeforces.com/problemset/problem/998/A)

## 问题描述

给定长度n的整数数组a，要求从a中选出m个元素满足：

1. m个元素的和 * 2 > 数组的和
2. m < n



## 问题思路

为了使得m个元素的和尽可能大，我们可以选择n-1个最大值。



总结：

如果n-1个最大值的和等于最小值，那么输出-1

否则，输出n-1个最大值的索引（只要选择最小值的索引，循环整个数组时排除即可）



## 实现代码

```c++
#include<iostream>

int n, a[1001];
int main(){
	std::cin >> n;
	
	int idx = - 1, mi = 1001, sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] < mi) {
			mi = a[i];
			idx = i;
		}
		
		sum += a[i];
	}
	
	if(n == 1 || sum == a[idx] * 2) {
		std::cout << "-1\n";
		return 0;
	}
	
	std::cout << n-1 << "\n";
	for(int i = 0; i < n; i++) {
		if(i != idx) {
			std::cout << i + 1 << " ";
		}
	}
	std::cout << "\n";
	return 0;
} 
```



## 要点

贪心