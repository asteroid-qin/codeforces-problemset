# C. [Best Binary String](https://codeforces.com/problemset/problem/1837/C)

## 问题描述

给一个0-1字符串，定义cost为反转字符串的连续子串得到非递减字符串的最小操作数。如果0-1字符串有?字符（？可以变成0或者1），输出cost最小的确定的字符串。

比如：

- 10111，不包含?，所以输出原字符串并且cost是1。
- 001?，输出0011，cost是0。而不是0010，因为它的cost是1。



## 问题思路

判断有没有0在1的后面？找到第一个字符1的下标idx，如果后面出现字符0，那么代表0在1后面出现。

如果没有。idx找不到默认值是n。循环一遍字符串，idx前面的？都是0，后面的？都是1。

如果有。idx前面的？都是0，后面的？分类讨论：

1. 0?0：此时?需要化作0。它是前一个值。
2. 1?1：此时?需要化作1。它是前一个值。
3. 1?0：此时?是0是1都行，cost都是1。它可以是前一个值。
4. 0?1：此时?是0是1都行，cost都是1。它可以是前一个值。

综上，我们让后面所有的?都取决于前一个字符的值，尽可能让字符串**连续**。



## 实现代码

```c++
#include<iostream>

int t, n;
void slv() {
	std::string s;
	std::cin >> s;
	n = s.size();
	
	char pre = '0';
	for(char& c : s) {
		if(c == '?') c = pre;
		else pre = c;
	}
	std::cout << s << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 

```



## 要点

分类讨论

# D. [Bracket Coloring](https://codeforces.com/problemset/problem/1837/D)

## 问题描述





## 问题思路





## 实现代码

```c++

```



## 要点

分类讨论





