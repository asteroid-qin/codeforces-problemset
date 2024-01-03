# B. [Lovely Palindromes](https://codeforces.com/problemset/problem/688/B)

## 问题描述

给定整数n，求出第n个偶数回文数字



## 问题思路

尝试输出1-10000内的所有偶数来找规律：

首先长度为2的：11、22、33、44、55、66、77、88、99

首先长度为4的：1001、1111、1221、1331、1441、1551、1661、1771、1881、1991

...



注意到：第k个回文串，一定是以k个为开头，倒置k为结尾。

比如：第19个回文串，k是19，所以是 1991。

结论不难证明。



总结：

读入一个字符串s，输出s，再输出倒置s。



## 实现代码

```c++
#include<iostream>

std::string s; 
int main() {
	std::cin >> s;
	std::cout << s;
	for(int i = s.size() - 1; i >= 0; i--) std::cout << s[i];
	std::cout << "\n";
	return 0;
}
```



## 要点

找规律