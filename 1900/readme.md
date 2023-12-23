# A. [Cover in Water](https://codeforces.com/problemset/problem/1900/A)

## 问题描述

给n个单元格，有3种状态：空、装水、锁住。可以选择操作：

1. 往空的里面装水
2. 把装水变为空，把另一个空转变为装水

当一个空被左右两边的装水围住时，它会变成装水。



现在求把所有空变为装水的执行选择1的最少次数。



## 问题思路

不关心2的执行次数，可以任意执行。而且被围住时，水可以无限生成，所以有结论:



如果存在3及以上个连续的空，那么答案是2。



其他情况，直接计数即可。



## 实现代码

```c++
#include<iostream>

int t, n;
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		int cnt = 0;
		bool f = false;
		for(int i = 0; i < n; i++) {
			if(i - 1 >= 0 && i + 1 < n && s[i] == s[i-1] && s[i] == s[i+1] && s[i] == '.') {
				f = true;
				break;
			}
			
			if(s[i] == '.') {
				cnt++;
			}
		}
		
		if(f) {
			cnt = 2;
		} 
		
		std::cout << cnt << "\n";
	}
	return 0;
} 
```





## 要点

贪心