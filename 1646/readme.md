# B. [Quality vs Quantity](https://codeforces.com/problemset/problem/1646/B)

## 问题描述

给个长度n的数组（元素>=0），定义3种状态，可以为每个元素设置其中一个。现在：

1. 定义cnt(x) 表示 状态是x的元素的个数，
2. 定义sum(x) 表示 状态是x的元素的和



判断能否构造一个，使得：sum(0) > sum(1) 且  cnt(0) < cnt(1)。



## 问题思路

先对数组排序：倒序。



先尝试满足第一个条件：



n是偶数：n=2k

0使用[1, k-1]，1使用[k+1, 2k]。显然这是0能取到的最大cnt，如果此时还不满足条件1那么无解。

左边选择k-1个, 右边选k个



n是奇数：n=2k+1

左边选择k个，右边选k+1个



综上：前(n-1)/2个元素的和必须大于后面的



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		long long sumb = 0, suma = 0;
		
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		std::sort(a+1, a+1+n);
		
		// 倒着k个
		int k = (n-1) / 2;
		for(int i = n; i >= n+1-k; i--) {
			suma += a[i];
		}
		
		k++;
		// 顺着k+1个
		for(int i = 1; i <= k; i++) {
			sumb += a[i];
		} 
		
		if(suma > sumb) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
```



## 要点

排序 贪心