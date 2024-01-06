# A. [Holidays](https://codeforces.com/problemset/problem/670/A)

## 问题描述

给定整数n，其构造规则有7种：

1. 以0开头，得到2个0，然后得到5个1。5个1的后面是2个0，2个0的后面是5个1...一直循环直到得到n个元素
2. 以0开头，得到1个0，然后得到5个1。5个1的后面是2个0，2个0的后面是5个1...一直循环直到得到n个元素
3. 以1开头，得到5个1，然后得到2个0。2个0的后面是5个1，5个1的后面是2个0...一直循环直到得到n个元素
4. 以1开头，得到4个1，然后得到2个0。2个0的后面是5个1，5个1的后面是2个0...一直循环直到得到n个元素
5. 以1开头，得到3个1，然后得到2个0。2个0的后面是5个1，5个1的后面是2个0...一直循环直到得到n个元素
6. 以1开头，得到2个1，然后得到2个0。2个0的后面是5个1，5个1的后面是2个0...一直循环直到得到n个元素
7. 以1开头，得到1个1，然后得到2个0。2个0的后面是5个1，5个1的后面是2个0...一直循环直到得到n个元素



现在要求，这7种排列中包含最多的和最少的0的数量



## 问题思路

显然，第1种能包含最多的0，第3种则包含最少的0。



令 k = n / 7，r = n % 7, 显然：

第1种是：k * 2 + min(2, r)

第3种是：k * 2 + max(0, r - 5)



## 实现代码

```c++
#include<iostream>

int n;
int main() {
	std::cin >> n;
	int k = n / 7, r = n % 7;
	
	int a = k * 2 + std::min(2, r);
	int b = k * 2 + std::max(0, r - 5);
	
	std::cout << b << " " << a << "\n";
	return 0;
} 
```



## 要点

贪心