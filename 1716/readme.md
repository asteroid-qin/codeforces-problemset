# B. [Permutation Chain](https://codeforces.com/problemset/problem/1716/B)

## 问题描述

从长度n的1-n的全排列$$a_1$$开始，交换任意两个元素得到$$a_2$$，并且$$a_2$$的值严格小于$$a_1$$。$$a_i$$的值定义为：$$p_i=i$$的数量。现在要求满足条件的最大的k。



## 问题思路

一开始$$a_1$$的值是n，因为一次最少让值-1，所以k的最大值是n。

现在考虑如何让$$a_1$$的值减少得更加缓慢。显然，任意一次操作会导致值-2。



假设先交换1和2。1和2的索引对不上！

再交换2和3...这样总是交换相邻的！这样每次都会-1，这样可以做n-2+1次，加上$$a_1$$，长度恒为n。



## 实现代码

```c++
#include<iostream>


int t, n, a[101];

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::cout << n << "\n";
		for(int i = 1; i <= n; i++) {
			a[i] = i;
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
		
		for(int k = 1; k < n; k++) {
			std::swap(a[k], a[k+1]);
			
			for(int i = 1; i <= n; i++) {
				std::cout << a[i] << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
}
```





## 要点

贪心