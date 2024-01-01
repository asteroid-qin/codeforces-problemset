# A. [Oath of the Night's Watch](https://codeforces.com/problemset/problem/768/A)

## 问题描述

给定长度n的整数数组a，求 存在a[j] < a[i] 且 a[k] > a[i]的i的数目。



## 问题思路

排序后答案就此揭晓：



求第一个大于a[0]的元素的索引：l

求第一个小于a[n-1]的元素的索引：r

答案便是：max(0, r - l + 1)



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int n, a[100000];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::sort(a, a+n);
	
	int l = 0, r = n - 1;
	while(l < n && a[l] == a[0]) l++;
	while(r >=0 && a[r] == a[n-1]) r--;
	
	std::cout << std::max(0, r - l + 1) << "\n";
	return 0;
}
```



## 要点

排序