# B. [Anti-Fibonacci Permutation](https://codeforces.com/problemset/problem/1644/B)

## 问题描述

给定n，输出n个 长度n的全排列且所有i满足反斐波那契数列：$$a_{i-2} + a_{i-1} \neq a_i $$。



## 问题思路

这还不简单，只要是降序就可以了。



因为$$a_{i-1} \gt a_i$$ 所以 $$a_{i-2} + a_{i-1} \neq a_i $$。



那输出： n n-1 n-2 ... 1 即可。



但是问题并没有这么简单，这只是其中一种，还需要找出n-1个。



最好是以i开头，然后构造后面n-1个数：让他们降序。



假如i=1，那么就是 1 n n-1 ... 2：依旧满足！

假如i=2，那么就是 2 n n-1 .. 1: 依旧满足！

假如i=n-1， 那么 n-1 n n-2 .. ：依旧满足！

假如i=n，那么n n-1 ... 1：依旧满足！



可以给个证明：

如果i不是n，得到序列 i n ... 1， 显然n是最大的，所以i+n比后面都要大，同时后面是递减的，绝对满足题意。

如果i是n，得到序列 n n-1 ... 1，显然也是符合题意的。



## 实现代码

```c++
#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << i;
			for(int j = n; j >= 1; j--) {
				if(j == i) continue;
				std::cout << " " << j;
			}
			std::cout << "\n";
		}
		
	}
	return 0;
}
```





## 要点

意识到倒序是其中一种排列方式。需要n个，那么循环i发现以i开头的倒序也是满足的