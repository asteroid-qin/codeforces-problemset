# A. [Split it!](https://codeforces.com/problemset/problem/1496/A)

## 问题描述

给定长度n的字符串s，判断能否找到k+1个字符串a，使得：

$$s = a_1 + a_2 + ... + a_k + a_{k+1} + R(a_k) + R(a_{k-1}) + ... R(a_1)$$



R(a) 表示反转字符串a。

## 问题思路

显然k*2+1 必须小于等于n。



注意到：s是以a1开头R(a1)结尾的。如果a1=xyz，那么R(a1)=zyx



发现规律：只要s[0]=s[n-1] 且 s[1]=s[n-2] 且 s[2]=s[n-3]，那么得到a1。其他都可以如法炮制。



我们贪心地以一个字符作为一个字符串，只要找到k个即满足题意。



也就是循环i，从0到k-1，要求每个s[i]=s[n-i-1]即可。

## 实现代码

```c++
#include<iostream>

int t, n, k;
std::string s;

bool check() {
	std::cin >> n >> k >> s;
	
	if(2*k+1 > n) {
		return false;
	}
	for(int i = 0; i < k; i++) {
		if(s[i] != s[n-i-1]) return false;
	}
	return true;
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

找规律