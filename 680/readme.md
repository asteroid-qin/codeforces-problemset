# A. [Bear and Five Cards](https://codeforces.com/problemset/problem/680/A)

## 问题描述

给定长度5的数组a，现在可以丢掉一些牌，如果满足：

1. 2个值都是相等的
2. 3个值都是相等的



现在求剩下a的和的最小值



## 问题思路

首先a是给定的，所以和要最小，丢的牌需要最大。



对需要丢的牌数分类讨论，显然最多有5种可能。

假设当前值是x，那么得到x出现的次数cnt，且让cnt = min(cnt, 3)。

如果cnt < 2，那么跳过。否则，用mx记录cnt * x，显然mx需要记录最大的cnt * x。



最后输出a的和 - mx即可。



## 实现代码

```c++
#include<iostream>

int n, a[5];
int main() {
	n = 5;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int sum = 0, mx = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		
		int cnt =  0;
		for(int j = 0 ; j < n; j++) {
			if(a[i] == a[j]) cnt++;
		}
		
		if(cnt < 2) continue;
		cnt = std::min(cnt, 3);
		
		mx = std::max(mx, cnt * a[i]);
	}	
	
	std::cout << sum -  mx << "\n";
	return 0;
} 
```



## 要点





# B. [Bear and Finding Criminals](https://codeforces.com/problemset/problem/680/B)

## 问题描述

给定长度n的数组a（a中只有0或者1），和整数x。要求从x开始向左右两边探测p个单位：

1. 如果x-p 和 x + p取不到，不处理
2. 如果x-p 或者 x + p 取不到，如果取得到的值是1，tot + 1，否则不处理
3. 如果x-p 和 x + p都取得到，如果取得到的值是2，tot + 2，否则不处理



一开始tot=0，现在p的范围在[1, n]，求tot的值。



## 问题思路

按照原题目描述过于繁琐，所以在描述时写了问题的思路。



实际上，这道题目只需要读完后照着模拟即可。



需要特别注意一点的，只有：a[x]可能等于1，所以需要额外判断。



## 实现代码

```c++
#include<iostream>

int n, x, a[101];
int main() {
	std::cin >> n  >> x;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	
	int ans = a[x] == 1;
	
	for(int i = 1; i <= n; i++) {
		int p = x - i, q = x + i;
		if(p >= 1 && q <= n) {
			if(a[p] + a[q] == 2) ans += 2;
		} else if(p >= 1) {
			ans += a[p] == 1;
		} else if(q <= n) {
			ans += a[q] == 1;
		}
	}
	
	std::cout << ans << "\n";
	
	return 0;
} 
```



## 要点

审题