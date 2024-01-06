# B. [Different is Good](https://codeforces.com/problemset/problem/672/B)

## 问题描述

给定长度n的字符串s，s仅有小写字母组成。现在可以任意改变a的一个字符，问：



使得a的所有子串都不同的最小更改次数。



## 问题思路

显然，a的最小子串的长度是1。因此a中每个字母只能出现一次，如果a的长度n>26，那么无论怎么改变都满足不了题意。



现在，n <= 26，只需要想办法让a的每个字符串都不相同。而如果a的每个字符都不同，则它的子串自然也是不同的。



总结：

n > 26，输出-1.

n <= 26，记录每个字母出现的次数。如果当前字母出现的次数x > 1，那么贡献是: x-1，否则是0，最后的答案便是贡献的和。



## 实现代码

```c++
#include<iostream>

std::string s;
int a[26], n;
int main() {
	std::cin >> n >> s;
	
	if(n > 26) {
		std::cout << "-1\n";
		return 0;
	}
	
	for(char ch : s) a[ch-'a']++;
	
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		if(a[i] > 1) ans += a[i] - 1;
	}
	std::cout << ans << "\n";
	
	return 0;
} 
```



## 要点

要满足题意，则a中每个字母只能出现一次