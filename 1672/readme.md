# B. [I love AAAB](https://codeforces.com/problemset/problem/1672/B)

## 问题描述

给定字符串s，假如一开始是空数组，现在可以往空数组插入好字符串任意次，判断能不能得到字符串s。



如果一个字符串长度大于2并且除了最后一个是'B'其他都是'A'，那么它是好字符串。



## 问题思路

一个好字符串仅仅只能提供一个'B'，所以s中有几个'B'，就代表需要执行插入几次。



首先保证最后一位是'B'，然后开始模拟。



我们可以用栈来模拟这个过程：

如果是'A'，直接压栈。

如果是'B'，栈顶必然有一个‘A'，把它弹出再把'B'弹出。这里是贪心地做法，尽量少消耗'A'，说不定后面还要用上。



## 实现代码

```c++
#include<iostream>
#include<stack>

int t;
std::string s;

void slv() {
	std::cin >> s;
	int n = s.size();
	
	if(n < 2 || s.back() != 'B') {
		std::cout << "NO\n";
		return;
	}
	
	std::stack<int> st;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') {
			st.push(i);
			continue;
		}
		
		if(st.empty() || s[st.top()] == 'B') {
			std::cout << "NO\n";
			return;
		}
		st.pop();
	}
	std::cout << "YES\n";
} 
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点

用'B'只匹配前面一个'A'，只要每个B都能匹配上就表示可以构成。