# B. [Difference of GCDs](https://codeforces.com/problemset/problem/1708/B)

## 问题描述

给定整数n、l、r，要求构造长度n的数组a，满足：

1. l <= a[i] <= r
2. gcd(i, a[i]) 各不相同





## 问题思路

我们都知道 gcd(i, a[i]) <= min(i, a[i])，现在要求构造n个都不同，也就是说得让gcd(i, a[i]) 得到1个长度n的1到n的全排列。



因为1的因子只有自己，所以任何数和他求gcd必然得到1。因此，如果比如出现2次1，那么没有解决方案。



这意味着：

a[1] 可以随便选择，从2开始，a[i] 必须与 i 有公因数 即 a[i] 是 i的倍数。



因为输出a的顺序没有要求，所以求解的顺序是随意的。我们可以从1到n开始求解a[i]。

对于当前i，如果 找到一个p使得  p % i == 0 且 l <= p <= r，那么a[i] = p 即可，否则答案无解。



求p也比较简单，令 i * k >= l  => k >= l / i   因此 p = (l + i - 1) / i * i        (向上取整)，再验证 p <= r即可



## 实现代码

```c++
#include<iostream>

int t, n, l, r;

void slv() {
	std::cin >> n >> l >> r;
	for(int i = 1; i <= n; i++) {
		int p = (l + i - 1) / i * i;
		if(p > r) {
			std::cout << "NO\n";
			return ;
		}
	}
	
	std::cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		int p = (l + i - 1) / i * i;
		std::cout << p << " ";
	}
	std::cout << "\n";
} 
int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
}
```



## 要点

gcd(i, a[i]) <= min(i, a[i]) => gcd(i,a[i])的结果是：1到n的全排列

a[i] 可以是i的倍数，构造1 2 3 4 ... n 这样的排列

