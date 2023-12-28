# A. [Distance and Axis](https://codeforces.com/problemset/problem/1401/A)

## 问题描述

给定a和k，要求找到一个b，使得abs(|a-b|-|b|) = k.



能直接找到，输出0。找不到，输出a需要移动的次数。

## 问题思路

对a与k分类讨论：

a = k,输出0.b可以放在0处。

a < k, 因为b无论怎么放，abs的结果都会小于k，所以需要移动a（朝右）。显然a应该直接移到k处，此时b可以取0或者k，这种情况的开销是：n-k。

a > k, b绝对应该小于b，并且有 k = a - b - b （当a - 2b >=0时），得出b = (k-a)/2，所以b是可以取到的。但是需要再讨论k和a的奇偶性，如果不同导致k-a得到一个奇数，那么就拿不到整数b，因此需要挪动a，开销是：1。否则是0



## 实现代码

```c++
#include<iostream>

int t, n, k;
int main(){
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;

		if(n < k) {
			std::cout << k - n << std::endl;
		} else if(n % 2 == k % 2) {
			std::cout << 0 << std::endl;
		} else {
            std::cout << 1 << std::endl;
		}
	}
	return 0;
} 
```



## 要点

数学