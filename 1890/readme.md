# A. [Doremy's Paint 3](https://codeforces.com/problemset/problem/1890/A)

## 问题描述

给一个长度n的数组a，可以任意改变元素的顺序。判断能否让数组a所有相邻的2个元素的和相等。



## 问题思路

假如
$$
b_i+b_{i+1}=k \\
b_{i+1}+b_{i+2} = k
$$
那么
$$
b_i=b_{i+2}
$$
所以，只需要计算数组a元素出现的个数。



如果是1，那么true；如果大于等于3，那么false

如果是2，那么保证其中一个元素出现的次数与另一个元素出现的次数相差不超过1。



## 实现代码

```c++
#include<iostream>
#include<map>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::map<int, int> mp;
			
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			mp[x]++;
		}
		
		if(mp.size() == 1 || 
			( mp.size() == 2 && abs(mp.begin()->second - mp.rbegin()->second)  <= 1 ) ) {
			std::cout << "YES\n";
			continue;
		}
		
		std::cout << "NO\n";
	}
	return 0;
} 
```



## 要点

推式子





# B. [Qingshan Loves Strings](https://codeforces.com/problemset/problem/1890/B)

## 问题描述

有两个01字符串s和t，现在可以任意次往s的任意位置插入t，现在判断能不能把s变得任意相邻的两个元素的值不同。



## 问题思路

什么时候必须插入t呢？遇到00或者11的时候。



此时插入的t的首字母必须合法。



那么t可以是不合法的吗？显然不行，我们无法改变t，往里面插只会无限循环，错误更多。



那么可以得到t是合法的，并且以什么开头，什么结尾。



循环s时候，遇到不合法的，判断头尾是否满足条件即可。



## 实现代码

```c++
#include<iostream>

std::string s, t;
int T, n, m;

int main() {
	std::cin >> T;
	while(T--) {
		std::cin >> n >> m;
		std::cin >> s >> t;
		
		
		
		bool f = true;
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) {
				f = false;
				break;
			}
		}
		if(f) {
			std::cout << "YES\n";
			continue; 
		}
		
		
		f = true;
		for(int i = 1; i < m; i++) {
			if(t[i] == t[i-1]) {
				f = false;
				break;
			}
		} 
		if(!f) {
			std::cout << "NO\n";
			continue;
		}
		
		
		char st = t[0], ed = t.back();
		f = true;
		
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) {
				if(s[i] != ed && s[i-1] != st) {
					continue;
				}
				
				f = false;
				break;
			}
		}
		
		if(f) std::cout << "YES\n";
		else std::cout << "NO\n";
	}	
	
	return 0;
}
```



## 要点

抓住重点t，研究t需要满足的性质