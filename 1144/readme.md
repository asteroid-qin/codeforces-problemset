# C. [Two Shuffled Sequences](https://codeforces.com/problemset/problem/1144/C)

## 问题描述

给定n个整数，要求把它们分成两个序列：a和b，满足：

1. a中所有元素严格单调递增
2. b中所有元素严格单调递减



## 问题思路

因为a和b都是严格单调的，所以一个元素最多只能出现2次。

因此，有如下思路：



如果有元素出现的次数超过2，那么直接输出NO

否则，先对n个整数排序，然后循环两次：

1. 第1次把输出所有出现为2次的元素（题目规定a或b的长度可以为0）
2. 第2次把输出所有出现过的元素（题目规定a或b的长度可以为0）



## 实现代码

```c++
#include<iostream>
#include<vector>
#include<algorithm>

int t, n, a[200001];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a+n);
	
	std::vector<int> p, q;
	// 出现3次 
	for(int i = 2; i < n; i++) {
		if(a[i] == a[i-1] && a[i] == a[i-2]) {
			std::cout << "NO\n";
			return 0;
		}
	}  
	
	q.push_back(a[0]);
	for(int i = 1; i < n; i++) {
		if(a[i] == a[i-1]) {
			p.push_back(a[i]);
		} else {
			q.push_back(a[i]);
		}
	}
		
	std::cout << "YES\n";
	std::cout << p.size() << "\n";
	for(int v : p) std::cout << v << " ";
	std::cout << "\n";
	
	std::cout << q.size() << "\n";
	for(int i = q.size() - 1; i >= 0; i--)
		std::cout << q[i] << " ";
	std::cout << "\n";
	return 0;
}
```





## 要点

排序