# A. [Crossmarket](https://codeforces.com/problemset/problem/1715/A)

## 问题描述

...又臭又长。



有n*m的单元格，一个人从1，1要去n，m，另一个则从n，1去1，m。每次只能选择一个人移动到相邻的单元格，移动一次的开销是1。现在在移动的路径可以花费1进行任意跳转（路径是共用的），现在求最少花费。





## 问题思路

先只考虑第一个人，尝试只移动它，发现它必须移动n-1+m-1下。



再考虑第二个人，如果第一个人走的是90度，那么有一列是可以直接从第n行跳到第1行，设这列是k。



那第二个人的开销则是：k-1+1+m-k=m。发现这个k被取消了，所以和k无关。



综上，输出n+m+m-2。



但是不一定非要先移动第一个人，可以先移动第二个人，如此会得到：m+n+n-2。



因此输出min(n+m+m-2,m+n+n-2)。此外还需要排除n=1和m=1的特殊情况。



## 实现代码

```c++
#include<iostream>


int main() {
	int t, n, m;
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		if(n == 1 && m == 1) {
			std::cout << "0\n";
			continue;
		}
		
		if(m > n) std::swap(n, m);
		
		std::cout << n + m + m - 2 << "\n";
	}
	return 0;
}
```





## 要点

大胆假设



# B. [Beautiful Array](https://codeforces.com/problemset/problem/1715/B)

## 问题描述

给整数n、k、b、s。要求构造长度n的非负整数数组a，数组a的和是s，并且$$ \sum\limits_{i=1}^{n} \lfloor \frac{a_i}{k}  \rfloor = b$$。



## 问题思路

考虑s的最小值：假设n等于1，那么显然s=kb。如果n为多个，可以让除了第一个数其他所有数的值为0，这样又回到n等于1的情况，s=kb。可以归纳证明，s必然大于等于k*b。



现在考虑s的最大值：假设n等于1，那么显然s=kb+k-1。如果n为多个，同理归纳为s必然小于等于(n-1)(k-1) +kb+k-1。



现在只需要判断s在范围内不？

如果在，特别设置第一个值是kb。s减去kb。

再循环一遍，如果当前s大于0，当前a[i]=min(s, k-1)，s再减去a[i]。



## 实现代码

```c++
#include<iostream>

int t;
long long n, k, b, s, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k >> b >> s;

		if( k*b <= s && s <= (n-1)*(k-1)+k*b+k-1 )	{
			for(int i = 0; i < n; i++) {
				a[i] = 0;	
			}
			a[0] = k*b;
			s -= k*b;
			
			for(int i = 0; i < n; i++) {
				long long x = std::min(s, k - 1);
				s -= x;
				a[i] += x;
			}
			
			for(int i = 0; i < n; i++) {
				std::cout << a[i] << " "; 
			}
			std::cout << "\n";
			
			continue;
		}
		
		std::cout << "-1\n";
	}
	return 0;
}
```





## 要点

考虑n=1，再推广到任意数；研究s的最大值和最小值。