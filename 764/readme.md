# B. [Timofey and cubes](https://codeforces.com/problemset/problem/764/B)

## 问题描述

给定长度n的整数数组a，从i=1开始，如果i <= n - i + 1，那么翻转a的区间[i, n-i+1]。



现在知道完成翻转后的a，求最初的a。



## 问题思路

对n分类讨论，有：



如果n是奇数，那么：

第1次翻转：[1, 2k+1]

第2次翻转：[2, 2k] ：和第1次抵消

第3次翻转：[3, 2k-1]

...

第k次翻转：[k k+2]



显然：如果是第奇数次翻转，才需要真的翻转。



如果n是偶数，那么：

第1次翻转：[1, 2k]

第2次翻转：[2, 2k-1] : 和第1次抵消

第3次翻转：[3, 2k-2]

...

第k次翻转：[k, k+1]

显然，n是奇数的情况一样



总结：

循环i, 从1开始，要求i * 2 <= n+ 1，每次i++。

对于当前i，如果i是奇数那么交换a[i, n-i+1]，否则不处理。

最后输出处理后的a即可



## 实现代码

```c++
#include<iostream>

int n, a[200001];
int main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for(int i = 1; i * 2 <= n + 1; i++) {
		if(i&1) std::swap(a[i], a[n-i+1]);
	}
	
	for(int i = 1; i <= n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
```



## 要点

模拟