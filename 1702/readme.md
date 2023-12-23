# A. [Round Down the Price](https://codeforces.com/problemset/problem/1702/A)

## 问题描述

输入m，输出k。k<=m且是10的幂次方。



## 问题思路

把m转成字符串，得到长度。



可以快速算出这个长度下的10幂次方。



输出它们差即可



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> m;
		std::string s = std::to_string(m);
		int sz = s.size();
		int k = pow(10, sz-1);
		
		std::cout << m - k << "\n";
	}
	
	return 0;
}
```





## 要点

字符串处理、结果找答案。