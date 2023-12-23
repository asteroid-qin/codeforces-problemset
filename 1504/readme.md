# A. [Déjà Vu](https://codeforces.com/problemset/problem/1504/A)

## 问题描述

给定字符串s，要求插入任意位置处一个a，使得s不是一个回文串。



## 问题思路

可以放在最后面，此时如果s不是回文就输出结果。

否则放在最前面，此时如果s不是回文就输出结果。



如果两种都不满足就代表s是一个全是a的回文串。

证明如下：

1. s[1]=a, s[2]=s[n],s[3]=s[n-1],...
2. s[n]=a, s[1]=s[n-1],s[2]=s[n-2],...

由上述两条得出，s[i]=a。此时无论怎么放a，s都是一个回文。



## 实现代码

```c++
#include<iostream>

bool judge(std::string& s) {
	int l = 0, r = s.size() - 1;
	while(l < r) {
		if(s[l] != s[r]) return false;
		l++; r--;
	}
	return true;
} 

std::string s;
int t;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		s += "a";
		if(!judge(s)) {
			std::cout << "YES\n" << s<< "\n";
			continue;
		}
		
		s.pop_back();
		s = "a" + s;
		if(!judge(s)) {
			std::cout << "YES\n" << s<< "\n";
			continue;
		}
		
		std::cout << "NO\n";
	} 
	return 0;
}
```



## 要点

利用回文串的性质证明