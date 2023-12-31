# A. [Ehab Fails to Be Thanos](https://codeforces.com/problemset/problem/1174/A)

## 问题描述

给定长度2 n 的整数数组a，要求重新排序，满足：

1. 前n个元素的和不等于后n个元素的和



## 问题思路

如果所有元素都相等，那么无论怎么排列都满足题目要求



否则，可以对a排序，这样前n个和一定小于后n个元素的和。



简单证明：

排序后，有：

a1 <= a(n+1)

a2 <= a(n+2)

...

an <= a(2n)



把它们列加起来知道：

前n个元素的和 <= 后n个元素的和（等号当且仅当所有元素相等的情况下成立）



总结：

只要出现a[i] != a[i-1]，那么就不是全等，输出排序后的a

否则，输出-1



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int n, a[2000];
int main() {
	std::cin >> n;
	n *= 2;
	bool f = true;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		
		if(i != 0 && a[i] != a[i-1]) {
			f = false;
		}
	}
	
	if(f) {
		std::cout << "-1\n";
		return 0;	
	}
	std::sort(a, a+n);
	
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	return 0;
} 
```



## 要点

排序+不等式