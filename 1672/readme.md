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



# C. [Unequal Array](https://codeforces.com/problemset/problem/1672/C)

## 问题描述

给定长度n的整数数组a，记p为a中相邻元素相等的数量。现在有1种操作可以选择2个相邻元素变为任意值，问：



将p变为<= 1的最小操作。



## 问题思路

相邻操作变为任意值，如果 a[i] = a[i+1]，显然应该想办法变a[i-1], a[i] 或者 a[i+1], a[i+2]，而这个操作本质是：

破坏原来相邻性：p-1，增加新的相邻性：p+1，这似乎会维持动态平衡。

但如果原本a[i-1] = a[i] 或者 a[i+1] = a[i+2]，整体的p的值会-1。且每次操作，p最多-1。



现在考虑所有相邻元素相等的点对(i, i+1)，我们可以从点最小（索引最小）往点最大（索引最大）合并。

如果不合并，那么p永远>1，那么就不妨从左往右合并，又因为这个过程中，所有的值都会被重新赋予，所以可以把中间元素当作为完全相同的1来处理。



设l是 a[i] = a[i + 1]的最小i，j 是 a[i-1] = a[i]的最大j。

问题就变为让长度 j - i + 1的，全是1的数组b，让它p <= 1的最小操作。



显然这是有规律的，简单试2个数，找出规律：



记长度为len：

如果len < 3，答案是0

如果len = 3，答案是1

如果len > 3，答案是len - 3



## 实现代码

```c++
#include<iostream>

int t, n, a[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		int st = 0;
		while(st + 1 < n && a[st] != a[st + 1] ) st++;
		
		int ed = n-1;
		while(ed - 1 >= 0 && a[ed] != a[ed - 1] ) ed--;
		
		int len = ed - st + 1;
		if(len < 3) {
			std::cout << "0\n";
		} else {
			std::cout << std::max(1, len - 3) << "\n";
		}		
	}
	return 0;
} 
```



## 要点

操作的本质：

1. 破坏原来相邻性：p-1，增加新的相邻性：p+1
2. 相邻性可以会向左右移动
3. 移动可以理解为合并，应该划出1个尽可能小的移动区间，使得相邻性能够合并在1起（也就是p=1）