# A. [The Third Three Number Problem](https://codeforces.com/problemset/problem/1699/A)

## 问题描述

给一个整数n，输出三个数a, b, c，满足(a^b) + (b^c) + (a^c) = n。



## 问题思路

a、b、c可以相等，那就让b=c=0。

问题就变成了： a+a=n。



## 实现代码

```c++
#include<iostream>


int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n&1) std::cout << "-1\n";
		else std::cout << 0 << " " << n / 2 << " " << "0\n";
	}
	return 0;
}
```





## 要点

尝试把问题简单化



# B. [Almost Ternary Matrix](https://codeforces.com/problemset/problem/1699/B)

## 问题描述

给两个偶数n和m，要求构造一个n * m 的01矩阵，并满足每个i,j 都恰好有两个邻居的值和它不同。



## 问题思路



假如n=m=2。从0，0开始，令a[ 0 ] [ 0 ] = 0，则a[ 0 ] [ 1 ] = 1，a[ 1 ] [ 0 ] = 1，所以 a[ 1 ] [ 1 ] = 0。

尝试扩充m：n=2，m=4。从0，0开始和上面一样，像是这样：

0 1 1 0

1 0 0 1

继续扩充m：n=2，m=6。发现依旧可以用到上面的结论！

0 1 1 0  0 1

1 0 0 1  1 0

n=2, m=8

0 1 1 0  0 1  1 0

1 0 0 1  1 0  0 1

1 0 0 1  1 0  0 1

0 1 1 0  0 1  1 0

0 1 1 0  0 1  1 0

1 0 0 1  1 0  0 1



如此，总算得出规律：





## 实现代码

```c++
#include<iostream>

int a[2][50];
int t, n, m;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int k = 0, x = 0; k < m; k += 2) {
			a[0][k] = x; a[0][k+1] = 1 - x;
			a[1][k+1] = x; a[1][k] = 1 - x;
			x = 1 - x; 
		}
		
		for(int i = 0; i < m; i++) {
			std::cout << a[0][i] << " ";
		}
		std::cout << "\n";
		
		for(int i = 0; i < m; i++) {
			std::cout << a[1][i] << " ";
		}
		std::cout << "\n";
		
		
		for(int k = 2, x = 1; k < n; k += 2) {
			for(int j = 0; j < m; j++) {
				std::cout << a[x][j] << " ";
			}
			std::cout << "\n";
			
			for(int j = 0; j < m; j++) {
				std::cout << a[1-x][j] << " ";
			}
			std::cout << "\n";
			x = 1 - x; 
		}
		
	}
	return 0;
}
```





## 要点

从2*2开始，找规律