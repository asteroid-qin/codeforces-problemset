# A. [Array and Peaks](https://codeforces.com/problemset/problem/1513/A)

## 问题描述

构造一个长度n的全排列，使得恰好有k个峰。



$$如果存在a_{i-1} < a_i 且 a_{i+1} < a_i ， 那么称i处是一个峰。$$

## 问题思路

从最小的峰开始构造。

显然3可以作为第一个峰，如果n>=3。

1 3 2

5作为第二个峰，如果n>=5：

1 3 2 5 4

7作为第三个峰，如果n>=7：

1 3 2 5 4 7 6

...

发现规律，总结为：

长度n能够构造的最多峰是：(n-1)/2， 所以k必须小于等于这个值。



至于构造的过程：从i=2开始循环，如果k>0，那么交换i与i+1，然后k--，否则不交换。每次输出两个数，i+=2。

因为n为偶数会漏掉最后一个数，所以得补上。



## 实现代码

```c++
#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(k > (n - 1) / 2) {
			std::cout << "-1\n";
			continue;
		}
		
		std::cout << 1 << " ";
		for(int i = 2; i+1 <= n; i+=2) {
			if(k > 0) {
				std::cout << i+1 << " " << i << " ";
				k--;
			} else {
				std::cout << i << " " << i + 1 << " ";
			}
		}
		if(n % 2 == 0) {
			std::cout << n;
		}
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

从小到大构造----> 交换相邻2个就可以得到一个峰顶