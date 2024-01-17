# A. [Mocha and Math](https://codeforces.com/problemset/problem/1559/A)

## 问题描述

给长度n的整数数组a，可以执行操作：选择l，r然后把a中[l,r]的每个元素与a中[l, r]翻转得到的元素按照位置一一做与操作。



现在想让数组a的最大值最小，求这个最大值。

## 问题思路

题目的数据范围里，数组a最小的元素是0，而0与任何数都是0.而操作可以让所有数都与0，因此如果有0，那么输出0.



贪心地想，如果存在被执行的l，r序列能够使得a的最大值最小，因为&操作是封闭的，所以顺序并没有要求。

先尝试把相邻的2个元素与操作。很快就会发现每次与都会导致相邻两个元素相等。从前往后走，会得到一个固定值。



而这个值就是最小值。因为其中每一位的1，每个a都包含，自然无法再小了。



综上：循环a，每个元素做&操作。

## 实现代码

```c++
#include<iostream>

int n, t;
int main () {
	std::cin >> t;
	while(t--) {
		int x;
		std::cin >> n >> x;
		for(int i = 1; i < n; i++) {
			int y;
			std::cin >> y;
			
			x &= y;
		}
		
		std::cout << x << "\n";
	}
	return 0;
} 
```



## 要点

发现先相邻2个元素与操作对最小值没有影响。发现循环执行相邻2个元素的与操作得到的结果就是最小值。



# C. [Mocha and Hiking](https://codeforces.com/problemset/problem/1559/C)

## 问题描述

给定n+1个节点，它们从1到n+1编号，现在有2*n-1条边：

1. n-1条边是，从i到i+1（1 <= i <= n-1）
2. n条边由a[i]描述（1<=i<=n），如果a[i]=0，那么有条从i到n+1的边；否则，是从n+1到i的边。



现在要求找出一条可行路径，使得n+1个节点恰好只走一遍



## 问题思路

比较简单的：如果a[n] = 0，那么直接输出1到n+1即可。



否则必然需要以n作为结尾，这表示：

1. 要么从1出发，从n-1跳到n+1，再从n+1走到n

2. 要么从n+1出发，跳到1再一直走到n

3. 要么从1出发，中途在k处跳到n+1，再从n+1跳到k+1，最后走到n



注意到1可以合并到3里面，所以综上只需要对以上三种情况特殊判断即可，其他情况都是无解的。



## 实现代码

```c++
#include<iostream>

int t, n, a[10001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int idx = -1;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if(i != 1 && a[i] == 1 && a[i-1] == 0) {
				idx = i;
			}
		}
		
		if(!a[n]) {
			for(int i = 1; i <= n+1; i++) {
				std::cout << i << " ";
			}
			std::cout << "\n";
			continue;
		}
		
		if(a[1]) {
			std::cout << n + 1 << " ";
			for(int i = 1; i <= n; i++) {
				std::cout << i << " ";
			}
			
			std::cout << "\n";
			continue;
		}
		
		if(idx != -1) {
			for(int i = 1; i < idx; i++) {
				std::cout << i << " ";
			}
			
			std::cout << n + 1 << " ";
			
			for(int i = idx; i <= n; i++) {
				std::cout << i << " ";
			}
			
			std::cout << "\n";
			continue;
		}
		std::cout <<"-1\n";
	}
	return 0;
} 
```



## 要点

分类讨论