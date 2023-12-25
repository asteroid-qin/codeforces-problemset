# A. [Specific Tastes of Andre](https://codeforces.com/contest/1438/problem/A)

## 问题描述

构造长度n的数组a，使得a的任意子串都满足：子串的和被子串的长度整除。

## 问题思路

没啥好说的，注意到a中每个元素可以相等，不妨让a由n个1构成，显然这是符合题意的。



## 实现代码

```c++
#include<iostream>

int t, n;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << "1 ";
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

贪心



# B. [Valerii Against Everyone](https://codeforces.com/contest/1438/problem/B)

## 问题描述

给定一个长度n的数组b，定义$$a_i=2^{b_i}$$, 求找到数组a的两段不相交的子区间，使得子区间的和相等。



注意！区间长度可以为1.

## 问题思路

最简单的可能：存在两个相等的数，这样选择这两个数的的下标作为区间即可。



否则，答案无解。证明这个结论需要对2进制数有所了解。



2的bi次方，意味着1这个数向左移动bi次：注意只有这一个1其他全是0。

不存在相等的两个数意味着，如果我选择一段区间做加法不会出现进位：任意区间的和都不会导致二进制进位。



因此比较相等只能1位1位地比较，但是因为不存在相等的数，也就是我这个x处有个1，但是找不到2进制数这个x处也为1。因为一位都不想等，所以全都不等。故没有答案。



## 实现代码

```c++
#include<iostream>
#include<set>

int t, n;

bool check() {
	std::cin >> n;
	std::set<int> st;
	
	int x;
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		st.insert(x);
	}		
	return st.size() != n;
} 
int main() {
	std::cin >> t;
	while(t--) {
		if(check()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
```



## 要点

2进制数的性质