# C. [OKEA](https://codeforces.com/problemset/problem/1634/C)

## 问题描述

构造一个n*m的二维数组，1-n * m中元素恰好出现一次。满足条件：任意一行的一段连续元素的平均数是整数。



## 问题思路

当m=1时，显然怎么拜访都可以。

当m=2时，需要保证每列两个元素的和是个偶数。

​	1）n是奇数。1-2n中有n个奇数和n个偶数，因为会多出一个无法配对的奇数，所以排除

​	2）n是偶数。1-2n中有n个奇数和n个偶数。先输出所有的奇数，再输出所有的偶数即可。

当m=3时，需要每行满足：

a+b % 2 ==0   => a+b是偶数

b+c % 2 ==0	=>b+c是偶数

要么a、b、c都是偶数，要么都是奇数



a+b+c % 3 == 0 => 



0 1 0 1

0 1 0 1



1 3 5   

2 4 6 



显然不可能每行都是偶数，m=3依旧不满足

当m=4时，需要每行至少满足：

a+b%2==0=>a+b是偶数

b+c%2==0=>b+c是偶数

c+d%2==0=>c+d是偶数

也就是每行的要么全是奇数，要么全是偶数



## 实现代码

```c++
#include<iostream>

int t, n, m; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		if(m == 1) {
			std::cout << "YES\n";
			for(int i = 1; i <= n; i++) {
				std::cout << i << "\n";
			}
			continue;
		}
		// 有多少个奇数？(n+m)/2 ， 
		int k = (n*m)/2;
		
		if(k % m != 0) {
			std::cout << "NO\n";
			continue;
		} 
		
		int p = k / m;
		std::cout << "YES\n";
		
		// 先输出k/m行 m 列 的奇数 再同样输出偶数
		for(int i = 0, x = 1; i < p; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << x << " ";
				x += 2;
			}
			std::cout << "\n";
		}
		
		for(int i = 0, x = 2; i < p; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << x << " ";
				x += 2;
			}
			std::cout << "\n";
		}
	}
	return 0;
}
```





## 要点