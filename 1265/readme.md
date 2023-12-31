# A. [Beautiful String](https://codeforces.com/problemset/problem/1265/A)

## 问题描述

给定长度n的字符串s，s中只包含'a' 'b' 'c' '?'，现在需要替换所有的'?'为'a' 或 'b' 或 'c'，使得s中所有的相邻字符不同。



## 问题思路

可以定义dp[i] [j]:

dp[i] [0]: 第i个字符的值是'a'，[1, i]的合法性

dp[i] [1]: 第i个字符的值是'b'，[1, i]的合法性

dp[i] [2]: 第i个字符的值是'c'，[1, i]的合法性



如果s[i]的字符是'a' 'b' 'c' ，显然另外两个都是false，只有自己才是true。

如果s[i]的字符是'?'，那么 dp[i] [j] = dp[i-1] [ (j + 2) % 3]  | dp[i-1] [ (j + 2) % 3]。



最后判断dp[n] [0] |  dp[n] [1]  | dp[n] [2]  是否为true即可。



当然这题并不需要使用dp，也可以贪心地做：

循环两边：

第一次，所有的'?'都替换为'a'

第二次，所有的'?'如果和前一个相等，那么替换为另一个元素。（因为有3种可能，所以一定找得到）

第三次，判断是否合法。



这种思路也可以优化：把第一次和第二次合并。这里就不过多赘述，实现比较简单。

## 实现代码

```c++
#include<iostream>

int t;
std::string s, a;
bool has[3];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		int n = s.size();
		a.resize(n);
		
		// 1.		
		for(int i = 0; i < n; i++) {
			if(s[i] == '?') a[i] = 'a';
			else a[i] = s[i];
		}
		
		// 2.
		for(int i = 0; i < n; i++) {
			if(s[i] != '?') continue;
			
			for(int j = 0; j < 3; j++) has[j] = 0;
			
			if(i - 1 >= 0) {
				has[a[i-1]-'a']=1;
			}
			if(i + 1 < n) {
				has[a[i+1]-'a']=1;
			}
			
			for(int j = 0; j < 3; j++) {
				if(!has[j]) {
					a[i] = j + 'a';
					break;
				}
			}
		}
		
		// 3. 
		bool check = true;
		for(int i = 1; i < n; i++) {
			if(a[i] == a[i-1]) {
				check = false;
				break;
			}
		}

		if(!check) {
			std::cout << "-1\n";
			continue;
		}	
		std::cout << a << "\n";
	}
	return 0;
} 
```



## 要点

替换'?'为与相邻元素不等的值