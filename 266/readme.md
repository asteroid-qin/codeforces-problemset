# B. [Queue at the School](https://codeforces.com/problemset/problem/266/B)

## 问题描述

给定长度n的字符串s（仅由'B'和'G'字符组成），执行t次操作。在每次操作：使用i从0开始，循环s。如果s[i]='B'且s[i+1]='G'，那么交换s[i]和s[i+1]，且i+2，否则i+1。



现在求执行t次操作后的s。



## 问题思路

这里的n和t都比较小，所以可以直接按照题意模拟。



## 实现代码

```c++
#include<iostream>

int n, t;
std::string s;
int main() {
	std::cin >> n >> t >> s;
	
	while(t--) {
		for(int i = 0; i < n - 1; i ++) {
			if(s[i] == 'B' && s[i+1] == 'G') {
				std::swap(s[i], s[i+1]);
				i++;
			}
		}
	}	
	std::cout << s << "\n";

	return 0;
}
```



## 要点

模拟

