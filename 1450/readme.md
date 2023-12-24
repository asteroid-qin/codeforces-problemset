# A. [Avoid Trygub](https://codeforces.com/contest/1450/problem/A)

## 问题描述

给定长度n的字符串s，要求重新排列使得不包含"trygub"这个子序列。



## 问题思路

贪心地想，b是在t的后面的，在"trygub"里。

所以我们只需要按照升序排列s即可，这个过程可以优化为计数排序。



## 实现代码

```c++
#include<iostream>

int t, n, cnt[26];
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(char ch : s) cnt[ch-'a']++;
		
		for(int i = 0; i < 26; i++) {
			char ch = i + 'a';
			while(cnt[i] > 0) {
				std::cout << ch;
				cnt[i]--;
			}
		}
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

贪心