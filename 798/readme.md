# A. [Mike and palindrome](https://codeforces.com/problemset/problem/798/A)

## 问题描述

给定字符串s，判断能否改变恰好一个字符使得s成为一个回文串。



## 问题思路

可以求一个字符串需要变为回文串的开销：



双指针i=0,j=n-1，循环条件i < j。

再定义tot为开销，如果a[i] != a[j], tot++。

每次i++, j--。



问题似乎到此为止：上述方法可以求出开销，显然只需要开销 <= 1即可。



但是题目要求恰好改变一个字符，如果开销等于1最好，

如果等于0且s的长度是偶数时，这意味没有字符允许被改变，此时需要输出 NO。



## 实现代码

```c++
#include<iostream>

std::string s;
int main() {
	std::cin >> s;
	int n = s.size();
	int i = 0, j = n - 1, tot = 0;
	while(i < j) {
		if(s[i] != s[j]) tot++;
		i++; j--;
	}
	
	if(tot == 1 || (tot == 0 && (n & 1))) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
} 
```



## 要点

求出通常开销