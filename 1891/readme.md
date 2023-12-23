# A. [Sorting with Twos](https://codeforces.com/problemset/problem/1891/A)

## 问题描述

给一个长度n的整数数组a，可以执行任意次操作：选择2的次方数m，把1到2的m次方的数组a的所有数减去m。现在判断能否让数组a，不降序排列。



## 问题思路

首先，如果1到2的m次方内是有序的，那么同时去掉一个数不会对顺序造成任何影响。



关键是[1, 2^m] [2^m+1, 2*2^m]，这里得保证两个区间都是有序的，否则输出false。



m=0, [1, 1] [2, 2]

m=1, [1, 2] [3, 4]

m=2, [1, 4] [4, 8] 

...

发现这里只需要保证 [2^m+1, 2*2^m] 有序即可



## 实现代码

```c++
#include<iostream>

int t, n, a[22];

bool check(int l, int r) {
	while(l + 1 <= r) {
		if(a[l] > a[l + 1]) {
			return false;
		}
		l++;
	}
	return true;
}

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		if(n <= 2) {
			std::cout << "YES\n";
			continue;
		}
		
		int p = 2;
		bool f = true;
		while((1 << p) <= n) {
			int ed = 1 << p;
			int st = ed / 2 + 1;
			if(!check(st, ed)) {
				f = false;
				break;
			}
			
			p++;
		}
		
		if(f && check((1 << (p-1) ) + 1, n)) {
			std::cout << "YES\n";
			continue;
		}
		
		std::cout << "NO\n";
	}
	return 0;
}
```



## 要点

原本有序，去掉相同的数，不会对顺序有影响。