# A. [Least Product](https://codeforces.com/problemset/problem/1917/A)

## 问题描述

给定长度n的整数数组a，可以执行任意次操作：

1. 选择一个a[i]， 如果a[i] < 0 ，可以把a[i] 替换为 [a[i], 0]之间的数。如果a[i] > 0，可以把a[i] 替换为[0, a[i]]



定义r为执行任意次操作后得到的a的最小乘积

定义k为得到r的最小操作数



需要输出k，k次具体操作



## 问题思路

最小乘积？如果存在a[i] = 0，因为无法把0转为非0数，所以r=0，k=0



因为不能把正数变为负数，负数变为正数，所以如果最终结果是大于0的数，需要随便选一个值，把它变为0



如果小于0，那么不需要再操作，k=0



总结：

第1次循环，如果a[i] = 0，直接输出 0

第2次循环，记录符号转换，一开始opt = 1，如果a[i] > 0，那么不做处理，否则opt *= -1。

​	最终, 得到:

​	opt = 1？输出:

​	1 

​	1 0

​	opt = -1? 输出：

​	0



## 实现代码

```c++
#include<iostream>

int t;
int n, a[100];

void slv() {
	std::cin >> n;
		
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	bool sym = true;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			std::cout << "0\n";
			
			return;
		}
		
		if(a[i] < 0) sym = !sym; 
	}
	
	if(sym) {
		std::cout << "1\n1 0\n";
	} else {
		std::cout << "0\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
```



## 要点

贪心