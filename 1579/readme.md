# E1. [Permutation Minimization by Deque](https://codeforces.com/problemset/problem/1579/E1)

## 问题描述

准备一个空的双端队列dq，给定长度n的整数数组a，现在会循环一边数组，对于每一个当前元素有2中操作：

1. 把它加到dq的首部
2. 把它加到dq的尾部



循环完成后，得到a的新排列。现在求这个新排列最小字典顺序是？



## 问题思路

可以维护当前的最小值。

如果遍历的值是最小值，那么把他放在首部，否则放在尾部。



## 实现代码

```c++
#include<iostream>
#include<deque>

int t, n;

void slv() {
	std::cin >> n;
	int mi = 2e5;
	
	std::deque<int> dq;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		mi = std::min(mi, x);
		if(x == mi) dq.push_front(x);
		else dq.push_back(x);
	}
	
	while(!dq.empty()) {
		int x = dq.front();
		dq.pop_front();
		std::cout << x << " ";
	}
	std::cout << "\n";
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点

贪心