# A. [Increasing and Decreasing](https://codeforces.com/problemset/problem/1864/A)

## 问题描述

给定三个整数x、y、n，要求构造长度n的数组a，满足：

1. a[1] = x, a[n] = y
2. a严格递增
3. 定义b[i] = a[i+1] - a[i]，那么 b 严格递减



## 问题思路

可以令a[1]=x，从2开始递推，因为一定要增加，所以a[i] = a[i-1]+1即可。



最后只要手动让an=y即可。这么看1、2两条都满足了，并且a增长的最为缓慢，如果还不满足题意那么无解。



关键是第3条，需要a增长的越来越慢。



因此只能从a[n-1]开始，让a[i-1] = a[i] - (n - i)，i从n-1到2。这样a递减的也是最缓慢，如果还不满足，那么无解。



总结：

手动令a[1] = x， a[n] = y，

倒序令 a[i-1] = a[i] - (n-i) ，2 <= i <= n-1，

建议是否合法，合法直接输出a即可



## 实现代码

```c++
#include<iostream>

int t, x, y, n, a[1001];

void slv() {
	std::cin >> x >> y >> n;
	a[n-1] = y;
	int p = 1;
	for(int i = n-2; i >= 0; i--) {
		a[i] = a[i+1] - p;
		p++;
	}
	
	if(a[0] < x) {
		std::cout << "-1\n";
		return;
	}
	
	a[0] = x;
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点

贪心



# B. [Swap and Reverse](https://codeforces.com/problemset/problem/1864/B)

## 问题描述

给定长度n的字符串s，和整数k。可以执行下面2个操作任意次：

1. 将s[i]与s[i+2]交换
2. 将 [i, i+k-1] 区间所有元素翻转



现在问：s的最小字典序。



## 问题思路

先通过第1个操作将问题简单化：

01010101010

得到一个长度s的01字符串，0和0相连，1和1相连。



现在研究k：

当k为奇数时，如果k选择'0'作为起点，那它必然同样以'0'结束。因为0和1是交替出现的，所以k选择的是一个回文串，反转没有任何意义。如果k选择'1'作为起点，同上。



当k为偶数时，如果k选择'0'作为起见，那它必然以'1'结束。也就是说，反转后，这个长度k的区间里面所有的值会变化：'0'变成'1'，'1'变成'0'。这一步抽象的操作可以理解为任意相邻2个元素可以交换，也就是冒泡排序的思想，因此，可以直接对整个s排序。



总结：

k是奇数，将s按照奇偶索引分别排序

k是偶数，输出排序后的s



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t;
int n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		
		std::string s, a, b;
		
		std::cin >> s;
		
		if(k & 1) {
			for(int i = 0; i < n; i++) {
				if(i&1) a += s[i];
				else b += s[i];
			}
			
			std::sort(a.begin(), a.end());
			std::sort(b.begin(), b.end());
			
			int p = 0, q = 0;
			for(int i = 0; i < n; i++) {
				if(i&1) s[i] = a[p++];
				else s[i] = b[q++];
			}
		} else {
			std::sort(s.begin(), s.end());
		}
		
		std::cout << s << "\n";
	}
	return 0;
}
```



## 要点

将得到的数据抽象，从而能够研究本质（代码写起来简单，但是想到这个点，对我来说真的难）

