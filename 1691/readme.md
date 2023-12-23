# B. [Shoe Shuffling](https://codeforces.com/problemset/problem/1691/B)

## 问题描述

输入长度n的单调不递减整数数组a，输出长度n的1-n的全排列p，满足a[i] >= a[p[i]]。



## 问题思路

如果n个数全相等，答案很简单，输出1-n接口。



如果n-1个数全相等，只有一个值是大于前面n-1个数的。那么找不到a[i] >= i 且 i != n，所以输出-1。



如果是小于n-1个数，那显然可以找到：p[0]=2-1中随便一个数即可。



发现规律！如果最大值只有一个，因为无法找到另一个大于等于最大值的索引，所以输出-1。

否则k个最大值之间可以两两相交换。

接下来考虑次大值，显然次大值无法选择最大值，因为每个最大值只能被使用一次，这会导致某一个最大值找不到匹配的！因此，可以把最大值全部去掉，得到新的数组，次大值变为最大值又回到原先的问题。如此一来，便得到一个重要的结论：



把数组a按照a[i]分组，必须满足每个组的大小都大于1。输入答案可以把每个分组理解为一个环。



## 实现代码

```c++
#include<iostream>

int t, n, a[100001];

void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	// 先校验
	if(n == 1) {
		std::cout << "-1\n";
		return;
	}
	
	// 头尾 
	if(a[1] != a[2] || a[n] != a[n-1]) {
		std::cout << "-1\n";
		return;
	}
	
	for(int i = 2; i < n; i++) {
		if(a[i] != a[i - 1] && a[i + 1] != a[i]) {
			std::cout << "-1\n";
			return;
		}
	}
	 

	int i = 1;
	while(i <= n) {
		// 找j，使得a[i] = a[i+1] = ... = a[j]
		int j = i + 1;
	 	while(j <= n && a[j] == a[i]) j++;
	 	j--;

		// 输出答案
		for(int k = i; k <= j; k++) {
			if(k == i) std::cout << j << " ";
			else std::cout << k - 1 << " ";
		}	 
		i = j + 1;
	}
	std::cout << "\n";
}


int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	
	return 0;
}
```





## 要点

从最大值开始着手，发现分组后，每组都是各用各的。