# A. [Regular Bracket Sequence](https://codeforces.com/contest/1469/problem/A)

## 问题描述

给定长度n的括号序列s：只由 '('、')'、'?' 构成。现在可以把'?'替换为'('或者')'，问能否使得s是一个合法的括号序列。



注意审题！s中的'('和')'**恰好**出现一次。

## 问题思路

一开始读题没有读清楚，导致自己写下了第一版的代码：s中的'('和')'无论出现多少次都有效。

悲伤....我还想说这个道出的恶心人。



如果有约束条件，那么问题就变得很简单了。

首先n必须是偶数，然后s的头部必须不是')'且尾部不是'('，那么必然有解。

那么问题是为什么呢？可以对'?'的数量分类讨论。



'?'出现0次，此时s只有一种可能："()"，显然是满足题意的。

'?'出现2次，那么因为'('只出现一次且不在最右边，那它的右边必然有')'或者'?'出现，这两种情况都可以使得'('被配对。同理')'也能够被配队，因此，对于s中的'('、')'如论如何都是可以配队的。而剩下的'?'怎么放都行。

'?'出现2次都满足，那么出现2*k次都是满足的，因此直接判断即可。



如此，写下第二版的代码。

## 实现代码

第一版

```c++
#include<iostream>
#include<vector>
#include<deque>

int t, n;
std::string s;

bool check() {
	std::cin >> s;
	n = s.size();
	if(n&1) {
		return false;
	}
	int cnt = 0, opt = 0;
	// oa放:(,ob放:),oc放:?
	std::vector<int> oa, ob;
	std::deque<int> oc;
	
	for(int i = 0; i < n; i++) {
		char ch = s[i];
		if(ch == '(') {
			oa.push_back(i);
		} else if(ch == ')') {
			if(!oa.empty()) oa.pop_back();
			else ob.push_back(i);
		} else {
			oc.push_back(i);
		}
	}
    // 得到 )))))(((((
	for(int i : ob) {
		if(oc.empty() || oc.front() > i) return false;
		oc.pop_front();
	}
	
	int sz = oa.size();
	for(int i = sz - 1; i >= 0; i--) {
		if(oc.empty() || oc.back() < oa[i]) return false;
		oc.pop_back();
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

第二版

```c++
#include<iostream>

int t, n;
std::string s;

bool check() {
	std::cin >> s;
	n = s.size();
	return (n % 2 == 0) && s[0] != ')' && s.back() != '(';
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

审题 贪心