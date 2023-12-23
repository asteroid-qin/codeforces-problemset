# B. [Roof Construction](https://codeforces.com/problemset/problem/1632/B)

## 问题描述

构造长度n的0到n-1的全排列，使得成本最小。成本是所有相邻元素异或的最大值。



## 问题思路

错误的异或会导致出现比n-1还大的值。把所有数写作二进制。



找到一个最大的2的幂次方数：100000...0

如果它就是最大值，那么把它和0放在一起。其他随便排列也不会超过它。

如果不是，用它+1的数把它消掉。但是不可能左右用比它大的数夹住，而是只能选择一边：这里选择右边。左边自然只能选择0断开。



于是，发现一个结论：最大值就是这个最大的2的次方数。



排列也变得简单：倒着 输出n-1到最大的2的次方数 ，再倒着 输出0到2的次方-1



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, n; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int p = 1;
		while(p * 2 <= n - 1) p *= 2;
		
		for(int i = p - 1 ; i >= 0; i--) {
			std::cout << i << " ";
		}
		
		for(int i = p; i < n; i++) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
```





## 要点

找到可能的最大值：

最大的2的幂次方数。一旦找到后，其他就好解决了



此外，发现一个bug：log(n-1)/log(2)失效了