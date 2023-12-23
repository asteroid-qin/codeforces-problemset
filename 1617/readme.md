# A. [Forbidden Subsequence](https://codeforces.com/problemset/problem/1617/A)

## 问题描述

给定两个字符串s、t。t是abc的某种排列，现在需要排列s，使得满足两个条件：

1. 字母顺序尽可能最小。
2. s中不存在子序列t。



## 问题思路

先排序吧，先满足第一点。



再对s中含有的元素分类讨论：

只有当s包含a、b、c且t是"abc"才需要替换s中b、c的顺序



## 实现代码

```c++
#include<iostream>
#include<vector>

int t, idx[128];

void slv() {
	std::string s, t;
	std::cin >> s >> t;
	
	std::vector<int> cnt(26, 0); 
	for(char ch : s) cnt[ch-'a']++;
	
	for(int i = 0; i < cnt[0]; i++) {
		std::cout << 'a';
	}	
	
	if( "abc" != t || !cnt['a'-'a'] || !cnt['b'-'a'] || !cnt['c'-'a'] ) {
		for(int i = 0; i < cnt[1]; i++) {
			std::cout << 'b';
		}
		for(int i = 0; i < cnt[2]; i++) {
			std::cout << 'c';
		}
	} else {
		for(int i = 0; i < cnt[2]; i++) {
			std::cout << 'c';
		}
		for(int i = 0; i < cnt[1]; i++) {
			std::cout << 'b';
		}
	}
		
	for(int i = 3; i < 26; i++) {
		while(cnt[i]--) std::cout << char('a'+i);
	}
	std::cout << "\n";
} 

int main(){
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
```





## 要点

先研究s



# B. [GCD Problem](https://codeforces.com/problemset/problem/1617/B)

## 问题描述

给定整数n，找3个不同的数：a、b、c。满足：

1. a+b+c=n
2. gcd(a,b)=c



## 问题思路

想让问题变得简单，不妨让c=1，这样问题变为：

找互质的a、b，且a+b=n-1。



如果n是偶数：n=2k

那么a=k，b=k-1即可。



如果n是奇数：

1.n=4k+1

2k-1, 2k+1, 1

gcd(2k-1,2k+1)=gcd(2k-1, (2k+1)%(2k-1)) = gcd(2k-1, 2)

2k-1是奇数，必然与2互质。



2.n=4k+3

2k-1, 2k+3, 1

gcd(2k+3, 2k-1)=gcd(2k-1, 4)

2k-1是奇数，必然与4互质



综上：

1. 是偶数：k-1，k，1
2. 对4取余得到1：2k-1, 2k+3, 1
3. 对4取余得到3：2k-1, 2k+3, 1

## 实现代码

```c++
#include<iostream>

int t, n;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

void slv() {
	std::cin >> n;
	if(n % 2 == 0) {
		std::cout <<  n / 2 << " " << (n / 2 - 1) << " " << 1 << "\n";
		return; 
	}
	
	for(int i = 2; i <= n; i++) {
		if(gcd(i, n-i-1) == 1) {
			std::cout << i << " " << n - i - 1 << " " << 1 << "\n";
			return;
		}
	}
}

int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
```





## 要点

数学