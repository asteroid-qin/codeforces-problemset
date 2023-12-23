# C. [Yet Another Permutation Problem](https://codeforces.com/problemset/problem/1858/C)

## 问题描述

给出一个n，要求找到一个从1到n的全排列a，定义$$d_i=gcd(a_i,a_{(i \ mod \ n)+1})$$，要求得到的数组d的不重复$$d_i$$的数量尽可能多。



## 问题思路


$$
关键是d_i的定义，i是从1到n的，如果i不为n那d_i=gcd(a_i,a_{i+1})
$$
因为全排列的数在1-n之间，所以不重复di的数量也是1-n之间。

1的话很好创建，和1相邻就有：必然会有1。

2的话需要存在两个两个相邻的数都是2的公倍数，最好就是：2 4。

3的话需要存在两个数是3的公倍数，最好是：3 6。

...



如果想要x，那么尽可能让x与x * 2与x * 4 .. x * 2^n 次方相邻。



1 10   100    1000  ... 1000

​    11  110    1100  ...  11000

​           101    1010  ...  10100

并且能取到的最大x是：n/2 向下取整。



所以，可以循环2-n，被使用了跳过。没有使用就从i跳到i*2跳到i * 4 ... 直到超过n。

最后再填入1。

## 实现代码

```c++
#include<iostream>

int t, n, a[100001];
bool vis[100001];
int main() {
	
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		
		int p = 1;
		for(int i = 2; i <= n; i++) {
			int j = i;
			
			while(j <= n && !vis[j]) {
				vis[j] = 1;
				
				a[p++] = j;
				
				j <<= 1;
			}
		}
		for(int i = 1; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "1\n";
	} 
	return 0;
} 
```





## 要点

胆子大