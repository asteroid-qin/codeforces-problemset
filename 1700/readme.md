# A. [Optimal Path](https://codeforces.com/problemset/problem/1700/A)

## 问题描述

给定n*m的数组a, a[ i ] [ j ]的值是(i-1) *m+j。现在找一条从左上到右下的路径，使得路径上的a[ i ] [ j ] 的和最小。



## 问题思路

一眼dp，但是这里m和n都比较大，所以得找规律：a[ i ] [ j ] 值的定义 是入口。



发现一个结论，假如存在一个a[i] [j] = x，那么有如下：

x 					x+1

x+m 			x+1+m



显然从x->x+1->x+1+m绝对比x->x+m->x+1+m要更优，但这是单位为1的情况。

考虑到从1，1到4，4的路线是：

例如：

![1](img\1.png)



发现a[1] [1] 可以为 x，套入上面公式发现这样更优：

![1](img\2.png)



同理a[2] [2]也是：

![1](img\3.png)

发现a[1] [2] 也可以操作：

![1](img\4.png)



这样可以每列每列地做下去，直到得到最终答案：

![1](img\5.png)



## 实现代码

```c++
#include<iostream>

int t;
long long n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;		
		std::cout << m * (m + 1) / 2 + ((n * (n + 1) / 2) * m) - m << "\n";
	}
	return 0;
}
```





## 要点

结论推广



# B. [Palindromic Numbers](https://codeforces.com/problemset/problem/1700/B)

## 问题描述

给定长度n的数位字符串a（由0到9组成），需要输出同样长度的数位字符串s（没有前导0），使得a+s能得到一个回文串b。



## 问题思路

既然是数与数之间运算，那就得考虑进位。



考虑最简单的情况，让b[i] 所有元素相等。而这个值最好就取9，因此 s[i] = 9 - a[i]，最后输出s[i]即可。



但是问题到这里并没有结束，题目要求了前导0，如果a[n] = 9，前导0就会出现。并且此时必须进位处理, 同时进位需要 (a[1] + s[1] ) % 10 = 1



此时最简单的解决部分就是使得b的所有元素都是1。



令 carry += a[i]，那么 b[i] = (11-carry) % 10，carry = (a[i] + b[i]) / 10



## 实现代码

```c++
#include<iostream>

int t, n, a[100002], b[100002];
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		for(int i = n; i >= 1; i--) {
			a[i] = s[n-i] - '0';
		}
		
		if(a[n] !=9) {
			for(int i = n; i >= 1; i--) {
				std::cout << 9 - a[i];
			}
			std::cout << "\n";
			continue;
		} 
		
		int carry = 0;
		for(int i = 1; i <= n; i++) {
			carry += a[i];
			b[i] = (11 - carry) % 10;
			carry = (a[i] + b[i] ) / 10;
		}
		
		for(int i = n; i >= 1; i--) {
			std::cout << b[i];
		}
		std::cout << "\n";
	}
	return 0;
}
```





## 要点

如果a[n]=9，那么可以想办法让b=1111111...11