# B. [Rising Sand](https://codeforces.com/problemset/problem/1698/B)

## 问题描述

给长度n的数组a。定义如果$$a_i > a_{i-1} + a_{i+1}$$，那么$$a_i$$是好的。给定k，可以让连续k个区间内的所有元素+1，该操作可以执行任意次。现在求能得到的好的$$a_i$$出现的最大次数。



## 问题思路

假如不执行操作，那循环一遍可以得到结果。



现在考虑区间+1，显然是把原来不好的现在变好。如果存在可以变好的值: a[ j ]，那么显然区间加1不能落在j j+1上，因为操作没有影响，同理也不能落在j-1 j 上。综上，应该是落在j上，才可以把原来坏的变好，也就是k必须为1，否则无效果。



现在考虑k为1能得到的最大值：

偶数-1，奇数不处理得到x，答案是x/2。



求两种情况的最大值即可。



## 实现代码

```c++
#include<iostream>

int a[200000], n, k, t;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		int cnt = 0;
		
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			
		}

		for(int i = 0; i < n; i++) {
			if(i - 1 >= 0 && i + 1 < n && a[i-1] + a[i+1] < a[i] )	{
				cnt++;
			}
		}
		
		if(k == 1) cnt = std::max(cnt , (n - 1) / 2);
		
		std::cout << cnt << "\n";
	}
	
	return 0;
}
```





## 要点

讨论k的用法，发现只有k=1才会起作用。发现此时 (n - 1) / 2是一种选择。