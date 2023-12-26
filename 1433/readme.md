# C. [Dominant Piranha](https://codeforces.com/problemset/problem/1433/C)

## 问题描述

给定长度n数组a，可以选择任意下标，判断左右元素是否小于当前值：如果小于，小于的相邻元素将被移除，且当前值会+1。



现在问，存在一个下标可以消除所有元素？（除了自己）

## 问题思路

小于？顺序，首先想到排序。

假如a是一个单调递增数组，显然我们选择最大值就可以保证消除所有元素。



但是最大值如果不唯一呢？全是最大值的情况下会导致互相无可奈何。但是只要存在一个非最大值，那么与他相邻的最大值就可以吃掉它并变为真正的最大值。

总结：

1. 求出数组a的最大值
2. 再循环a，如果当前是最大值且左右存在一个非最大值，那么返回当前索引。否则输出-1.

## 实现代码

```c++
#include<iostream>

int n, t, a[300000];

int work() {
	std::cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin>> a[i];
		mx = std::max(mx, a[i]);
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] != mx) continue;
		
		if((i - 1 >= 0 && a[i-1] != mx) || (i + 1 < n && a[i + 1] != mx) ) {
			return i+1;
		}
	}
	return -1;
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cout << work() << "\n";
	}
	return 0;
} 
```



## 要点

排序 、与非最大值相邻的最大值