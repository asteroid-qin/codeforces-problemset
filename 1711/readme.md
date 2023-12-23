# A. [Perfect Permutation](https://codeforces.com/problemset/problem/1711/A)

## 问题描述

要求构造一个长度n的1-n全排列的数组，使得$$p_i$$被i整除的数量最少。





## 问题思路

显然，从2开始，$$p_i$$应该是p-1。



至于1，因为任何数都被1整除，所以值是n即可。



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		std::cout << n;
		for(int i = 2; i <= n; i++) {
			std::cout << " " << i - 1;
		}
		std::cout << "\n";
	}
	return 0;
} 
```





## 要点

利用p不被p-1整除的特性（当p大于1时）。



这里给个证明：

p=1*(p-1)+1，其中0<=1<p。

p-1前面的k只能是1。显然r=1不为0。因此p不被p-1整除。