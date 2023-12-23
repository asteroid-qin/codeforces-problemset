# B. [Patchouli's Magical Talisman](https://codeforces.com/problemset/problem/1688/B)

## 问题描述

给长度n的整数数组a，可以执行两种操作：

1. 合并两个元素，新元素的值是原来两个的和
2. 减少一个元素（值是偶数），把一个元素的值变为原来的1/2。

现在问，使得数组a全为奇数的最少操作数是？

## 问题思路

如果有奇数，因为奇数+偶数还是奇数，因此只要有一个奇数，那么答案就是偶数的数量。



如果全是偶数呢？我们需要尽可能快的得到奇数。对所有元素求最小/2得到奇数的操作数k，答案就是：n-1+k



因为：

1次 n-1 个偶数

2次 n-1 个偶数

...

k次 n-1 个偶数 1个奇数



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int odd = 0;
		
		int ctx = 31;
		for(int i =0; i < n; i++) {
			int x; std::cin >> x;
			if(x&1) odd++;
			
			int cur = 0;
			while(x > 0) {
				if(x & 1) break;
				x >>= 1;
				cur++;
			}
			ctx = std::min(ctx, cur);
		}
		if(odd > 0) {
			std::cout << n - odd << "\n";
			continue;
		}
		// 全部都是偶数
		std::cout << n -1 + ctx << "\n";
	}
	return 0; 
} 
```



## 要点

贪心