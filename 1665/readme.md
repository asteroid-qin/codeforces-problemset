# A. [GCD vs LCM](https://codeforces.com/problemset/problem/1665/A)

## 问题描述

给定n，要求找到4个整数a,b,c,d，满足：

a+b+c+d=n 且  gcd(a,b) = lcm(c,d)



## 问题思路

令c=d=1，则a与b只需要互质即可且a+b=n-2。



显然可以让a=1，这样b=n-3即可。



总结：输出 1 n-3 1 1

## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::cout << 1 << " " << n-3 << " 1 1\n";
	}
	return 0;
}
```





## 要点

先想办法让lcm尽可能简单：显然让c=d=1最简单，这样就需要a与b互质，此时让a=1，那么必然互质，得到结果。



# B. [Array Cloning Technique](https://codeforces.com/problemset/problem/1665/B)

## 问题描述

给长度n的数组a，有两种操作：

1. 把数组a拷贝一份
2. 交换数组a与其他数组的任意两个元素



现在求得到一个数组里面值全等的最小操作数。



## 问题思路

对数组a里面的元素进行分组，假如有一个元素出现了n次，那么答案是0。



否则，出现的次数最大不过是n-1。我们可以求得出现的次数的最大值k。显然后续复制再交换这个数字最优，并且多个并不影响结果。



问题就变为：要复制多少次才有充足的元素可以组装成n？

答案是：(n+k-1)/k - 1次，并且得到元素 (n+k-1)/k * k 个。



现在问题是：要转移多少次才能得到一个全元素相等的数组？

显然应该定住一个数组，其他拷贝的数组都只是往里加。



因为元素依旧是足够的，所以只需要加n-k下即可。



总结： 输出 (n+k-1)/k-1+n-k。



然而问题到此并没有结束：为什么要单单地拷贝初始的呢？我们可以拷贝一次后再移动一个元素。使得k至少不为1。



先执行m次拷贝，得到mk个，把mk搬回来得到新的数组，再重复下去直到相等。



这里，认为m为1即可。循环这个过程，对数时间复杂度。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		
		int k = 0;
		int i = 0;
		while(i < n) {
			int j = i+1;
			while(j < n && a[j] == a[i]) j++;
			
			// [i, j-1]内a[i]相等
			k = std::max(k, j-i);
			
			// 跳转
			i = j; 
		} 
		
		int ans = 0;
		while(k < n) {
			// 移动 cnt 次 
			int cnt = std::min(k, n - k);
			
			// k加上移动
			k += cnt;
			
			// ans需要移动+复制 
			ans += cnt + 1; 
		}
		std::cout << ans << "\n";
	}
	return 0;
}
```





## 要点

意识到：每次都应该复制自身再交换，这样最优。