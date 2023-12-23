# B. [Balanced Remainders](https://codeforces.com/problemset/problem/1490/B)

## 问题描述

给定长度n的整数数组a（n被3整除），可以执行一次操作：将$$a_i$$变为$$a_i+1$$。

记k0为数组a中对3取余得0的数量，

记k1为数组a中对3取余得1的数量，

记k2为数组a中对3取余得2的数量，

现在问，使得数组a的k0=k1=k2的最小操作数是？



## 问题思路

可以对数组a的元素分类直接得到当前k0、k1、k2。

既然需要k0=k1=k2，并且k0+k1+k2=n，那么k0=k1=k2=n/3。



因此，需要对这三个数分类讨论：

如果k0=k1=k2=n/3，那么不需要+1操作，输出0.

否则，有两种可能：恰好一个 > n/3 和 恰好两个 > n 3。



恰好一个 > n/3，有三种可能：k0、k1、k2。可以贪心的从0开始+1操作，操作数就是k?-n/3的值。发现k0和k1只需要从0到2循环一遍就可以得到所有的操作数，而k2需要再从0到2循环一遍。



恰好两个 > n/2，有三种可能：k0 k1、k0 k2、k1 k2。同上，最多从0到2循环两遍就可以得到答案。



## 实现代码

```c++
#include<iostream>

int t, n, a[3];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int x;
		for(int i = 0; i < 3; i++) a[i] = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> x;
			a[x%3]++;
		}
		int k = n / 3, ans = 0;
		for(int i = 0; i < 3; i++) {
			int carry = a[i] - k;
			if(carry > 0) {
				ans += carry;
				a[i] -= carry;
				a[(i+1)%3] += carry;
			}
		}	
		for(int i = 0; i < 3; i++) {
			int carry = a[i] - k;
			if(carry > 0) {
				ans += carry;
				a[i] -= carry;
				a[(i+1)%3] += carry;
			}
		}
		std::cout << ans << "\n";	
	}
	
	return 0;
}
```



## 要点

分类讨论