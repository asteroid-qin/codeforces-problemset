# A. [2023](https://codeforces.com/problemset/problem/1916/A)

## 问题描述

给定长度n的整数数组b，判断其乘积能否被2023整除，如果能被整除，那么把因数分解为k个整数。



## 问题思路

问题描述的有点绕，其实非常简单。只需要计算出b的乘积：x，然后判断 2023 % x = 0 ? 即可。



如果等于，那么输出YES，紧接着：k-1 个 1 和 1个 2023/x

否则，输出NO



## 实现代码

```c++
#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		
		long long d = 1, x;
		for(int i = 0; i < n; i++) {
			std::cin >> x;
			d *= x;
		}
		
		if(2023 % d == 0) {
			std::cout << "YES\n";
			
			for(int i = 1; i < k; i++) std::cout << "1 ";
			
			std::cout << 2023 / d << "\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
```



## 要点

读题



# B. [Two Divisors](https://codeforces.com/problemset/problem/1916/B)

## 问题描述

给定整数a、b，要求构造一个x（1<=x<=1e9），满足：

1. a和b是x的最大2个因数
2. 1 <= a < b < x



~~碎碎念：题目太不严谨的，因为x才是x的最大因数，所以描述a和b，应该是：必须是非x的最大因数。~~



## 问题思路

虽然代码很短，但是对数论有一定要求。



首先确定x的范围，因为a和b都是x的因数，所以x必然是a和b的公倍数。即x = a * b / gcd(a, b) * m (m >= 1)。



对a、b分类讨论：



如果a是1，那么x=b * b（如果此时b不是质数，那么无解，但是题目没指出，呵呵）



**如果a是质数且b是质数：**

那么，x=a * b



**如果a是合数，b是质数：**

因为a < b，所以gcd(a, b) = 1，x= a * b * m(m >= 1)。

此时a必然存在>=2的因数p，因为x 被a * b整除，所以x也被 p * b整除，所以p * b也是x的一个因数，且大于b小于x，不满足题意，舍去。



**如果a是质数，b是合数：**

当 gcd(a, b) = 1，x = a * b * m，那么b存在一个>=2的因数p，使得x 被 p * a 整除，且大于a小于x，同时p * a != b，因此不满足题意，舍去。

否则，gcd(a, b) = a，令b = a * p（p > 1)，则 x= a * p * m（m > 1)。因为必须a第二大，所以 a * m = b = a * p 即 p = m，所以 x = a * p * p。



**如果a是合数，且b是合数：**

当 gcd(a, b) = 1，x = a * b * m，那么b存在一个>=2的因数p，使得x 被 p * a 整除，且大于a小于x同时p * a != b，因此不满足题意，舍去。

当 gcd(a, b) = d，a = p * d， b = q * d，x = a * p / d * m = p * q * d  * m( q > p)

​	如果m > 1，那么q * d * m > b ，如果此时a的p!=1，那么无解

​	如果m=1，对p * q 进行讨论：

​		x > p * q > a  且 p * q != b   => q > d，那么无解

​		x > p * q > b  =>  p > d，那么无解

​		综上: p < q <= d有解x = p * q * d，否则没解



总结：

如果a是1，那么x=b * b

如果gcd(a, b) = a，那么x=b * b / a

否则，x = a * b / gcd(a, b)



## 实现代码

```c++
#include<iostream>

int t;
long long a, b;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
			
		if(a == 1) {
			std::cout << b * b << "\n";
			continue;
		}
		
		if(gcd(a, b) == a) {
			std::cout << b * b / a << "\n";
		} else {
			std::cout << a * b / gcd(a, b) << "\n";
		}
	}
	return 0;
}
```



## 要点

分类讨论（巨折磨）



# C. [Training Before the Olympiad](https://codeforces.com/problemset/problem/1916/C)

## 问题描述

给定长度n的数组a。有一个游戏，如果a的长度为1，那么结束。否则可以任选两个不相等的下标i和j，然后把它们2个替换为1个数：

1. 如果ai + aj 是个偶数，那么替换为ai + aj
2. 否则，替换为 ai + aj - 1



现在两个人 A和B 轮流玩这个游戏，A 会使得最后的结果尽可能最大。B会使得最后的结果尽可能最小。A先起手。



现在要输出n个数：

第k个数表示： 以a的[1, k]区间作为起始数组，获得的结果（1 <= k <= n)。



## 问题思路

一眼没有思路，题干又臭又长。



想想看，如果全是偶数，那么直接输出a的和即可。

否则，我们需要处理掉这些奇数。

让A来处理，A一定会优先2个一起处理，消耗0

让B来处理，B一定会选择1个处理，消耗1



也就是1轮可以去掉3个奇数，我们可以对奇数的数量分类讨论：

令x = 奇数的数量，b = x / 3，r = x % 3

当 r = 0时，恰好处理地干干净净，因为B会消耗b个单位，答案是：a的和 - b

当 r = 1时，我们让a来处理，答案是： a的和 - b - 1

当 r = 2时，我们让b来处理，答案是：a的和 - b



剩下地就很好写了。注意需要开long long 和 对 i =1 时特判即可。



## 实现代码

```c++
#include<iostream>

int t;
int n, a[100000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		int x = 0;
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			
			if(a[i] & 1) x++;
			int b = x / 3, r = x % 3;
			
			if(i == 0) {
				std::cout << a[i] << " ";
				continue;
			}
					
			if(r == 1) std::cout << sum - b - 1 << " ";
			else std::cout << sum - b << " ";
		}
		
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

将问题转换为：A和B轮流处理奇数