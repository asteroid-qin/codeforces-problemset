# A. [Median Maximization](https://codeforces.com/problemset/problem/1566/A)

## 问题描述

构造n个非负数，使得它们的和是sum，且中位数尽可能最大。



只要输出中位数即可。

## 问题思路

分类讨论：

n=2k+1

对于中位数：左边尽量小，右边尽量小于是得到 ： 0 0 0  ... 0 a a a ... a。

所有有：a + k a <= sum  => a <= sum / (k+1)



n=2k

有：a + k a <= sum  => a <= sum / (k+1)





综上：输出 sum / (k+1)即可



## 实现代码

```c++
#include<iostream>

int t, n, s, k;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		k = n / 2;
		std::cout << s / (k + 1) << "\n";
	}
	return 0;
} 
```



## 要点

贪心 分类讨论



# B. [MIN-MEX Cut](https://codeforces.com/problemset/problem/1566/B)

## 问题描述

给定长度n的01字符串s，可以把它分割成任意个子串。定义MEX(s)：s中最小的未出现的数。



输出求s被分割成任意子串的MEX的和最小。

## 问题思路

如果不分割：MEX顶多是0、1、2.



考虑什么情况下是0？

显然是没有0的时候！s中没有一个0时，一旦有0那么答案必然大于0.



考虑什么情况下是1？

显然是有0，且没有1。

有0有1的话。所以相邻的1合并得到，所有相邻的0合并，得到：010101.... 显然0的个数就答案，这里必须只有一组相邻的0。



考虑什么情况是是2？

显然是不满足上面两点。



综上：计算断开连接的0的个数。

如果是0，答案是0。

如果是1或者s中没有字符1，答案是1

其他，输出2



## 实现代码

```c++
#include<iostream>

int main() {
	std::string s;
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		
		int n = s.size();
		int i = 0;
		int ans = 0;
		bool noOne = true;
		
		for(; i < n; ) {
			while(i < n && s[i] != '0') {
				i++;
				noOne = false; 
			}
			
			if(i < n) {
				ans++;
			}
			while(i < n && s[i] == '0') i++;
		}
		
		if(ans == 0) std::cout << "0\n";
		else if(ans == 1 || noOne) std::cout << "1\n";
		else std::cout << "2\n";
	}
	return 0;
} 
```



## 要点

贪心 着重研究0、1、2的情况



# C. [MAX-MEX Cut](https://codeforces.com/problemset/problem/1566/C)

## 问题描述

给2 * n 的01字符数组s，可以把s按照列分割多个子数组，定义MEX为其中最小的未出现的数。



现在问：分割得到的多个子数组的MEX的和，最大可能是？

## 问题思路



有4种可能：00 01 10 11.

01和10都是好的，不应该加入额外的。

00和11都是坏的，显然每个坏的都得找个坏的想办法凑个好的。



思路变为了：好的直接计数。把相邻的坏的分到一组，只需要取最上面的值，问题就变为：

00110011中能构成01的最大数量。



还是得用到MEX的特性，需要着重关注0，因为能最小提供一个1。然后对于每个0尝试找一个1，能找到贡献就是2.



## 实现代码

```c++
#include<iostream>

std::string s, a, b;
int t, n;

int slv() {
	int res = 0, m = s.size();
	
	for(int i = 0; i < m; i++) {
		if(s[i] == '0') res++;
	}
	bool hasZero = false, hasOne = false;
	
	for(int i = 0; i < m; i++) {
		if(s[i] == '0') hasZero = true;
		if(s[i] == '1') hasOne = true;
		
		if(hasZero && hasOne) {
			res++;
			hasZero = hasOne = false;
		}
	}
	return res;
}

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> a >> b;
		s = "";
		int ans = 0;
		
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				ans += 2 + slv();
				s = "";
			} else {
				s += a[i];
			}
 		}
 		
 		std::cout << ans + slv() << "\n";
	}
	return 0;
} 
```



## 要点

贪心 分组 dp



