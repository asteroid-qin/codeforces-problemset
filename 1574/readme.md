# A. [Regular Bracket Sequences](https://codeforces.com/problemset/problem/1574/A)

## 问题描述

给定n，构造n个长度2n的不同的合法括号序列。



## 问题思路

n=1，输出()

n=2，输出()(), (())

n=3，输出()()(), ()(()), ((()))



找到规律了！

可以递推：

n=x，输出() + n=x-1的x-1种，最后加上左n个括号和右n个括号。



最后一项是2500，所以可以预处理。

## 实现代码

```c++
#include<iostream>
#include<vector>

int t, n;
std::vector<std::string> ans[51];

void init() {
	ans[1].push_back("()");
	
	for(int i = 2; i <= 50; i++) {
		ans[i].resize(i);
		
		for(int j = 0; j < i-1; j++) {
			ans[i][j] = "()" + ans[i-1][j];
		}
		
		for(int j = 0; j < i; j++) {
			ans[i][i-1] += "(";
		}
		for(int j = 0; j < i; j++) {
			ans[i][i-1] += ")";
		}
	}	
}

void slv() {
	std::cin >> n;
	for(auto& v: ans[n]) {
		for(auto& s : v) {
			std::cout << s;
		}
		std::cout << "\n";
	}
}
int main() {
	init(); 
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点

递推