# B. [Omkar and Heavenly Tree](https://codeforces.com/problemset/problem/1583/B)

## 问题描述

要求构造n个结点的树，输出连接这个数的n-1条边，且满足：

1. 对于给定m个a[i]、b[i]、c[i]，要求从节点a[i] 到 节点 c[i] 不经过 b[i]



## 问题思路

注意到m的取值是 < n的，也就是说就算把所有b[i]都放入set中，也至少会有1个点不在set中。



可以令这个点为中心点，然后向其他n-1个节点建立连接。显然这既简单又符合题目要求。



## 实现代码

```c++
#include<iostream>
#include<set>

int t, n, m, a, b, c;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		std::set<int> has;
		
		while(m--) {
			std::cin >> a >> b >> c;
			has.insert(b);			
		}
		
		int mid = 1;
		for(int i = 1; i <= n; i++) {
			if(!has.count(i) ) {
				mid = i;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			if(i == mid) continue;
			std::cout << i << " " << mid << "\n";
		}
	}
	return 0;
} 
```



## 要点

选中1点，向其他点做边