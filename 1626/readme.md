# A. [Equidistant Letters](https://codeforces.com/problemset/problem/1626/A)

## 问题描述

输入一个由小写拉丁字母组成的字符串s，s中2个相等的字母的出现不会超过两次。现在需要对s重排序，满足：所有相等字母之间的距离都是相等的。



## 问题思路

把所有出现2次的列出来，输出两遍。再输出出现1次的。



## 实现代码

```c++
#include<iostream>

int t;
std::string s;
int cnt[26];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		for(int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}

		for(char ch : s) {
			cnt[ch-'a']++;
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 2) {
				std::cout << (char)(i+'a');
			}
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 2) {
				std::cout << (char)(i+'a');
			}
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 1) {
				std::cout << (char)(i+'a');
			}
		}
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

分类