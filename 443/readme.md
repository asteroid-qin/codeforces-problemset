# A. [Anton and Letters](https://codeforces.com/problemset/problem/443/A)

## 问题描述

给定字符串s，要求统计里面不同的字母的个数



## 问题思路

循环s，如果s[i]是字母那么a[s[i]]++，最后只要统计a[i]中不为0的个数。



## 实现代码

```c++
#include<iostream>

int a[26];

int main() {
	char ch;
	while((ch = getchar()) != '\n') {
		if('a' <= ch && ch <= 'z') {
			a[ch-'a']++;
		}
	}	
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		ans += a[i] > 0;
	}
	std::cout << ans << "\n";
	return 0;
}
```



## 要点

模拟