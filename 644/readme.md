# A. [Parliament of Berland](https://codeforces.com/problemset/problem/644/A)

## 问题描述

给定长度n的数组c，其c[i] = 1 & i，i属于[1, n]。



又给定整数a和b，表示一个a行b列的矩阵d。现在可以随便排列c中元素，判断能否让：任何0不与0相邻，任何1不与1相邻。



不能做到，输出-1。否则输出满足要求的矩阵d的排列。



## 问题思路

显然有一种构造方式是：

1 0 1 0

0 1 0 1

1 0 1 0

...



注意到：如果i + j 是奇数，那么a [i] [j] = 0，否则是偶数，a[i] [j]  = 1。



因此，我们可以先判断a * b >= n，不满足那么就没解，满足一定有解。

满足的话，循环a * b 这个矩阵：

​	如果i + j是偶数，从a中可选的奇数中随便挑出一个

​	如果i + j是奇数，从a中可选的偶数中随便挑出一个



d[i] [j] 默认值是0.



关于构造的正确性，以下有简单的证明：



假设i + j是奇数，那么可以让a[i] [j] = 0，因为 i + j是奇数，所以 i + j - 1和 i + j + 1都是偶数，而 a[i-1] [j] 、a[i] [j-1] 、a[i+1] [j] 、a[i] [j+1] 恰好都是偶数，所以值都是1。

所以有：

对于任何 a[i] [j] = 0，这种构造能保证四周全是1，也就是任何0不与0相邻，满足了题意。

同理，可以证明a[i] [j] = 1，这种构造使得四周全是0，同样满足题意。



两个合起来，证明完毕。



## 实现代码

```c++
#include<iostream>

int n, a, b;
int main() {
	std::cin >> n >> a >> b;
	
	if(a * b < n) {
		std::cout << "-1\n";
		return 0;
	}
	
	int x = 1, y = 2;
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			int cur = i + j;
			
			if(cur & 1) {
				if(y <= n) {
					std::cout << y << " ";
					y += 2;
				} else {
					std::cout << "0 ";
				}
			} else {
				if(x <= n) {
					std::cout << x << " ";
					x += 2;
				} else {
					std::cout << "0 ";
				}
			} 
		}
		
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

i + j的奇偶性