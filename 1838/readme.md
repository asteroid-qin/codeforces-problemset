# A. [Blackboard List](https://codeforces.com/problemset/problem/1838/A)

## 问题描述

长度为2的数组给定2个整数，执行以下操作n-2次：求任意2个数的绝对值，并放入数组。得到一个长度n的数组。现在最终的长度n的数组已经给了，求原始2个整数的其中一个。



## 问题思路

从绝对值入手，显然后面生成的所有数都是非负数，因此如果找到一个负数，那就是答案。

考虑其他情况，原始两个数乃至整个数组都是非负数。我们可以对数组进行排序，然后会想到一个事实，那就是非负数数组的最大值是无法作差得到的，也就是数组的最大值就是原始数组之一。



## 实现代码

```c++
#include<iostream>


int t, n, a[101];
void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	int mx = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < 0) {
			std::cout << a[i] << "\n";
			return;
		}
		mx = std::max(mx, a[i]);
	}
	
	std::cout << mx << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点

数学



# B. [Minimize Permutation Subarrays](https://codeforces.com/problemset/problem/1838/B)

## 问题描述

给一个长度n全排列，执行恰好一次操作使得全排列的子数组的数量最小，这个子数组必须满足自身也是一个全排列。操作是交换全排列的两个下标，也就是输出两个交换下标。



## 问题思路

从全排列方式着手，考虑全排列的可能：

举个例子：1，3，2，4，它的满足全排列的子数组有：

[1]，[1，3，2]，[1，3，2，4]

可以发现，一个全排列的子数组的至少有2个是满足全排列的：[1]和本身。长度n的全排列子数组想要朝着n+1伸展，那么它需要向左或右汲取一个数。因此我们想要让全排列的子数组的数量最少，应该从长度2开始就阻隔：把1和2间的距离拉得足够远。

拉的足够远并不是指把1或者2放在最左端和最右端，而是往它们中间插入一个只有长度扩充到n时，才满足全排列的数：全排列数组中的最大值n。

总结：得到1、2和最大值的索引，求索引的中间值。如果中间值属于最大值，那么答案是最大值的下标与最大值的下标，否则，就是中间值与最大值的索引



## 实现代码

```c++
#include<iostream>


int t, n, a[200001];
void slv() {
	std::cin >> n;
	
	int x, y, z; // n >= 3
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) x = i;
		else if(a[i] == 2) y = i;
		else if(a[i] == n) z = i;
	}
	
	if(x > y) std::swap(x, y);
	
	// x < y
	if(z > y) {
		std::cout << y << " " << z << "\n";
	} else if(z < x){
		std::cout << z << " " << x << "\n";
	} else {
		std::cout << z << " " << z << "\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点

数学

# C. [No Prime Differences](https://codeforces.com/problemset/problem/1838/C)

## 问题描述

给一个n×m的矩阵，要求填充1-n×m，并且满足任意相邻位置的差的绝对值不是一个质数。



## 问题思路

不妨大胆，令填充顺序从上到下，从左往右：

	1		2		3		..		m
	
	m+1		m+2		m+3 	.. 		2m
	
	2m+1	2m+2	2m+3	..		3m
	
	...
	
	(n-1)m+1 ...			..		nm

我们发现，左右相邻的差的绝对值始终为1，上下相邻的始终为m。如果m是偶数，那么显然就并不是质数，满足题目要求。

现在考虑m是奇数。

尝试从第二行开始，每行比上一行整行向左多移动1的单位，让上下相邻的差始终为m+1（偶数）。

当n为2时，这种构造显然是正确的，我们可以把这个构造扩展到任意自然数n都成立。

当前n个都成立时，此时第n和n+1行是：

```
... (n-1)m+1 	... 	nm-1	nm		...
... nm+2		...	 	(n+1)m 	nm+1	...
```

显然n+1也是满足的，证毕。



## 实现代码

```c++
#include<iostream>

int t, n, m, a[1000];

void slv() {
	std::cin >> n >> m;
	
	// 处理m是偶数 
	if(m % 2 == 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << i * m + j + 1 << " ";
			}
			std::cout << "\n";
		}
		return ;
	}
	
	
	// 第一行 
	for(int i = 0; i < m; i++) {
		a[i] = i + 1;
		std::cout << i + 1 << " ";
	}
	std::cout << "\n";
	
	// 第二行以后 
	for(int i = 1; i < n; i++) {
		// 向左移动1位
		int x = a[0] + m;
		for(int j = 1; j < m; j++) {
			a[j-1] = a[j] + m;
		}
		a[m-1] = x;
		
		// 输出
		for(int j = 0; j < m; j++) {
			std::cout << a[j] << " ";
		} 
		std::cout << "\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点

数学