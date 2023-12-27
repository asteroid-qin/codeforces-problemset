# A. [Finding Sasuke](https://codeforces.com/problemset/problem/1413/A)

## 问题描述

给定长度为偶数n的数组a，要求构造同样长度的数组b，使得ai * bi的和等于0。



注意！a和b中的元素都不为0.

## 问题思路

约束n是偶数一定是有目的的。



可以从n=2开始，判断：x y

显然只要构造: -y x，这样x * (-y)+x * y 就能得到一个0.



显然可以快速从2推广到到任意偶数都满足：

又因为n规定是偶数，每两个都可以这样操作。所以循环一遍a后，n/2 个 0 的和依旧是0。



总结：

循环i，从0开始，n结束。每次输出a[i+1] * -1 和 a[i]，然后 i + 2。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int n, t, a[100];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	for(int i = 0; i < n; i += 2) {
		std::cout << a[i+1] * -1 << " " << a[i] << " ";
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

找规律