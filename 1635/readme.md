# C. [Differential Sorting](https://codeforces.com/problemset/problem/1635/C)

## 问题描述

给定长度n的整数数组a，可以执行一种操作：

1. 选择索引 x, y, z（1 < x < y < z <= n），令a[x] = a[y] - a[z]



现在问能否执行不超过n次，使得a变得非递减



## 问题思路

这种问题，一般都是想办法简化：让所有数都相等。



注意到x < y < z，也就是最大的y和z分别是 n-1 和 n。

显然，如果a[z] >= 0，那么 a[y] - a[z] <= a[y]，以此前面 [1, y-1] 都可以变为 a[y] - a[z]，都是满足题目要求的。



而如果a[z] < 0，因为a[y] - a[z]  > a[y]，**所以我们不应该选择负数作为索引z**



那么我们应该去寻找 >= 0 的数，并且贪心地，这个数的索引应该是>=0的数中最大的。

记索引为idx，那么显然z应该等于idx，且y等于idx-1，我们可以保证[1, idx-1] 都是满足题目要求的



因此剩下地问题是判断[idx-1, n] 是否是非严格单调递增的。如果存在i，使得a[i-1] > a[i]，那么显然是无解的（因为执行操作也无意义）



## 实现代码

```c++
#include<iostream>
#include<vector>

struct Node{
	int x, y, z;
};

int t, n, a[200000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int idx = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(a[i] >= 0) {
				idx = i;
			}
		}
		
		bool ok = true;
		for(int i = idx; i < n; i++) {
			if(i - 1 >= 0 && a[i - 1] > a[i]) {
				ok = false;
				break;
			}
		}
		
		if(!ok) {
			std::cout << "-1\n";
			continue;
		}
		
		std::vector<Node> vec;
		for(int i = 0; i < idx - 1; i++) {
			vec.push_back({i+1, idx, idx+1});
		}
		
		std::cout << vec.size() << "\n";
		
		for(auto& nd : vec) {
			std::cout << nd.x << " " << nd.y << " " << nd.z << "\n";
		}
	}
	return 0;
} 
```



## 要点

注意到：应该a[i] >= 0的i作为z，并且贪心地：需要i尽可能大，同时i-1作为y