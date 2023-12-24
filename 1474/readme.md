# B. [Different Divisors](https://codeforces.com/problemset/problem/1474/B)

## 问题描述

给定正整数d，要求找到一个x，满足：

1. x至少有4个因数。
2. 每个因数的差的绝对值都不小于d。

## 问题思路

首先任何一个整数都至少有2个因数：1和它本身。

只有2个因数是质数，有多个则是合数。

考虑这道题：应该是找到一对p和q，其中p < q，且x=pq，p-1>=d，q-p >= d。



那么该如何确定呢？

首先找p！注意到p必然是第一个大于d的质数。如果不是，那么它的因数的差绝对不大于d，进而导致得到的x不满足题意。



那么剩下的问题就是如何找到q？

显然q必然是第一个大于d+p的质数。如果是质数，那必然贪心地选择第一个。如果是合数，必须满足它的因数的差大于d，这样的合数肯定是大于第一个大于d+p的质数的，所以贪心地，q选作为第一个大于d+p的质数。



那么有没有可能q是p*p呢？

首先，找到p，得到：

1. p-1>=d
2. p * p - p = p * (p - 1) >= pd >= d
3. p * p * p - p * p =  p * p * ( p - 1) >= p*p * d >= d

于是有： 1，p，p * p，p * p * p，满足题意。



但是p * p * p <  p * q 存疑。

要证明：p * p  < q。这个实在是无能为力，只能猜到1-100000里面所有的质数既可以满足题目要求。因此p * p 必然小于 q的 ?

d + p <= q <= ?



下面实现是找出尽可能多的质数，然后选出两个最小的符合要求的。

## 实现代码

```c++
#include<iostream>

const int N = 100000;
int t, d, p[N+9], idx;
bool np[N+9];

void init() {
	for(int i = 2; i <= N; i++) {
		if(np[i]) continue;
		p[++idx] = i;
		for(long long j = (long long)i * i; j <= N; j += i) {
			np[j] = true;
		}
	}
}
int main() {
	init();
	std::cin >> t;
	while(t--) {
		std::cin >> d;
		// 找第一个 
		int i = 1;
		while(i <= idx && p[i] - 1 < d) i++;
		
		int x = p[i];
		
		// 找第二个 
		i++;
		while(i <= idx && p[i] - x < d) i++;
		int y = p[i];
		
		std::cout << (long long) x * y << "\n";
	}
	return 0; 
} 
```



## 要点

质数  贪心