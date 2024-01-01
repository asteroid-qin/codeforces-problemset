# B. [3-palindrome](https://codeforces.com/problemset/problem/805/B)

## 问题描述

给定整数n，要求构造一个字符串s，满足：

1. s的长度为n
2. s的每个长度为3的子数组都不是回文
3. s仅有字母'a' 'b' 'c' 组成
4. s中的'c'出现要最少



## 问题思路

题目要求的是长度为3的回文子串不存在。因此对于每个s[i]，要求s[i-1] != s[i+1]。



不妨从长度3开始构造：

我们此时有s：bba。



我们尝试往s的后面增加一个新的字符，因为要它不等于s[n-1]='b'（这里令下标从1开始），所以我们只能选择'a'（尽可能少使用'c'），于是得到：bbaa

继续往后，往s的后面增加一个新的字符，要求它不等于s[n-1]='a'（这里令下标从1开始），显然可以选择'b'，于是得到：bbaab

...

显然，这样一直做下去，可以得到一个'c'出现次数为0的满足题意的s。



总结：

n小于3直接输出：b、bb、bba

否则，循环i，从3到n-1（这里令下标从0开始），从'a' 和 'b' 中选择一个不等于s[i-2]的字符作为s[i]。最后输出s[i]即可



## 实现代码

```c++
#include<iostream>

std::string s = "bba"; 
int n;
int main() {
	std::cin >> n;
	s.resize(n);
	
	if(n <= 3) std::cout << s << "\n";
	else {
		for(int i = 3; i < n; i++) {
			if(s[i-2] == 'a') s[i] = 'b';
			else s[i] = 'a';
		}
		std::cout << s << "\n";
	}
		
	return 0;
}
```



## 要点

对于每个s[i]，要求s[i-1] != s[i+1]