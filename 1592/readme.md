# B. [Hemose Shopping](https://codeforces.com/contest/1592/problem/B)

## 问题描述

给定长度n的数组a，和整数x，可以交换a[i] a[j]，如果满足：

1. |i - j| >= x



现在问能否使得a不严格单调递增



## 问题思路

我们都知道可以交换任意两个元素就相当于可以给数组a排序（基于冒泡排序的思想）



所以问题是，能否联通整个数组？

注意到：

1 [x+1, n]

2 [x+2, n]

...

x-1 [x*2, n]



显然，如果 x*2 <= n，那么所有下标都可以连通，因此可以输出YES

否则，我们需要判断a的排序前后，区间 [n-x+1, x] 是否相等。如果相等，那么输出YES，否则NO





## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, x, a[100001], b[100001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> x;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			b[i] = a[i]; 
		}
		if(2 * x <= n || n == 1) {
			std::cout << "YES\n";
			continue;
		}
		
		std::sort(b+1, b+1+n);
		
		bool ok = true;
		for(int i = n-x+1; i <= x; i++) {
			if(b[i] != a[i]) {
				ok = false;
				break;
			}
		}
		
		if(ok) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		} 
		
	}
	return 0;
} 
```





## 要点

冒泡排序的扩展