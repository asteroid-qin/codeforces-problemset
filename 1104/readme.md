# A. [Splitting into digits](https://codeforces.com/problemset/problem/1104/A)

## 问题描述

给定整数n，要求构造长度k的数位数组a，a满足：

1. a[i]的和=n
2. 1 <= a[i] <= 9
3. 不同a[i]最小

## 问题思路

不同的a[i]最少，最少也就是1，所以最好是a[i]都相等。



有一种情况就是a[i]都相等：a[i] = 1



总之：输出n个1即可。



## 实现代码

```c++
#include<iostream>

int n;
int main() {
	std::cin >> n;
	
	std::cout << n <<  "\n";
	for(int i = 0; i < n; i++) std::cout << "1 ";
	std::cout << "\n";
	return 0;
}
```



## 要点

贪心