# A. [Shell Game](https://codeforces.com/problemset/problem/777/A)

## 问题描述

给定长度3的数组a，a的初始值是0，但是有1个元素的值是1。



给定整数n，会执行n步，从i=1开始，到n结束：

如果i是奇数，那么交换a[0] a[1]

否则，交换a[1] a[2]



现在给定x，表示执行n步后，a[x]=1。



需要倒着求：最开始值是1的索引p。



## 问题思路

显然p有且仅有3种可能，可以对它分类讨论：



假如在中间，即p=1：

那么，显然有一个循环周期：6，使得p回到索引1处。

同理，求出p=0的循环周期：6

同理，求出p=2的循环周期：6



因此，把n缩小到0到6之间，再模拟即可。



### 实现代码

```c++
#include<iostream>

int n, x, a[3];
int main() {
	std::cin >> n >> x;
	n %= 6;
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) a[j] = 0;
		a[i] = 1;
		
		for(int j = 1; j <= n; j++) {
			if(j&1) std::swap(a[0], a[1]);
			else std::swap(a[2], a[1]);
		}
		
		if(a[x] == 1) {
			std::cout << i << "\n";
			break;
		}
	}
	return 0;
} 
```



## 要点

n一开始是2e9，正常模拟做不出来，需要找规律发现周期6，所以使得 n <= 6