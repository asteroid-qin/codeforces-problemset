# A. [Another String Minimization Problem](https://codeforces.com/problemset/problem/1706/A)

## 问题描述

给定长度n的数组a和长度m的数组b，数组a由1-m内的整数构成，数组b则全是B。现在可以执行n次操作，第i次操作可以选择$$a_i$$或者m+1-$$a_i$$，记作x，然后把b第x个字符替换成A。



现在要求执行操作后，b字典序最小。



## 问题思路

贪心地想，求min($$a_i$$, $$m+1-a_i$$)，如果之前设置过了，选择max($$a_i$$, $$m+1-a_i$$)设置为A。每次都记录（如果是A）。



## 实现代码

```c++
#include<iostream>

int a[51];
int main(){
	int t, n, m;
	
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		std::string b(m, 'B');
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		for(int i = 0; i < n; i++) {
			int x = a[i], y = m + 1 - a[i];
			if(x > y) std::swap(x, y);
			if(b[x-1]=='A') b[y-1] = 'A';
			else b[x-1] = 'A';
		}
		
		std::cout << b << "\n";
	}
	
	return 0;
} 
```





## 要点

贪心