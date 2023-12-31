# B. [Letters Rearranging](https://codeforces.com/problemset/problem/1093/B)

## 问题描述

给定字符s，判断能否重新排列使得s不是一个回文



## 问题思路

如果s中所有元素都相等，那么无论如何排列都是一个回文。



否则，我们可以给s排序使得 s[1] <= s[n]。



显然，当s[1]=s[n]时，s中所有元素都相等，s是个回文串。

否则，s不是。



总结：

排序s，然后判断s[1]==s[n] ?

相等，输出-1

否则，输出s



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t;
int main() {
	std::cin >> t;
	while(t--) {
		std::string s;
		std::cin >> s;
		int n = s.size();
		
		std::sort(s.begin(), s.end());
		if(s[0] == s[n-1]) {
			std::cout << "-1\n";
		} else {
			std::cout << s << "\n";
		}
	}
	return 0;
}
```



## 要点

贪心 + 排序