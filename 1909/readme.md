# B. [Make Almost Equal With Mod](https://codeforces.com/problemset/problem/1909/B)

## 问题描述

给定长度n的各个值不等的数组a，有1个k，令数组b，满足：b[i] = a[i] % k。



现在需要输出这个k，并使得b[i]恰好只含有2个不同的元素



## 问题思路

如果：

ai % k = x，那么

ai % 2k = x 或者 x + k



所以选定k=2，只需要从 2 4 8 ... 一直做下去即可。



但是为什么说这样做一定有解呢？

如果没有解，那么说明：a所有的值都相等，这符合题意，所以必然有解。



## 实现代码

```c++
#include<iostream>
#include<set>
#define ll long long
int t, n;

ll a[101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		for(ll x = 2; x <= 1e18;) {
			std::set<ll> st;
			
			for(int i = 0; i < n; i++) {
				st.insert(a[i] % x);
			}
			
			if(st.size() == 2) {
				std::cout << x << "\n";
				break;
			} else {
				x *= 2;
			}
		}
	}
	return 0;
} 
```



## 要点

二进制