# C. [Make Equal With Mod](https://codeforces.com/problemset/problem/1656/C)

## 问题描述

给定长度n的整数数组a，可以执行1种操作任意次：

1. 选择x( x >= 2)，然后令 a[i] = a[i] % x



现在问，能否使得a中所有元素都相等



## 问题思路

想办法让最终的结果全为0或者全为1（全为2或者3及其他都可以% 这个数得到0）



想要全为0，很简单，只需要每次%数组a的最大值即可。但是这样并不是一定是有解的：



如果1不存在，那么应该让所有元素等于0，显然每次取a的最大值取模，一定是可以做到的。



如果1存在，那么需要把所有元素等于1

想要全为1，很简单，只要每次%a的最大值-1即可。



但是如果存在a[i-1]+1=a[i]时：

选择a[i]-1，会出现 0 和 1（无解）

选择a[i-1]-1，会出现1和2，显然2只能得到0（无解）



可以总结为：

如果存在1且存在a[i-1]+1=a[i]，那么输出 NO

否则， YES



## 实现代码

```c++
#include<iostream>
#include<algorithm> 

int t, n, a[100001];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		std::sort(a, a+n);
		bool has0 = false, hasEq = false;	
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) has0 = true;
			
			if(i + 1 < n && a[i] + 1 == a[i+1] ) hasEq = true;
		}
		
		if(has0 && hasEq) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}
```



## 要点

对1是否存在，分类讨论