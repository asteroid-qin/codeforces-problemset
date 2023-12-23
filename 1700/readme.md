# A. [Optimal Path](https://codeforces.com/problemset/problem/1700/A)

## 问题描述

给定n*m的数组a, a[ i ] [ j ]的值是(i-1) *m+j。现在找一条从左上到右下的路径，使得路径上的a[ i ] [ j ] 的和最小。



## 问题思路

一眼dp，但是这里m和n都比较大，所以得找规律：a[ i ] [ j ] 值的定义 是入口。



发现一个结论，假如存在一个a[i] [j] = x，那么有如下：

x 					x+1

x+m 			x+1+m



显然从x->x+1->x+1+m绝对比x->x+m->x+1+m要更优，但这是单位为1的情况。

考虑到从1，1到4，4的路线是：

例如：

![1](img\1.png)



发现a[1] [1] 可以为 x，套入上面公式发现这样更优：

![1](img\2.png)



同理a[2] [2]也是：

![1](img\3.png)

发现a[1] [2] 也可以操作：

![1](img\4.png)



这样可以每列每列地做下去，直到得到最终答案：

![1](img\5.png)



## 实现代码

```c++
#include<iostream>

int t;
long long n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;		
		std::cout << m * (m + 1) / 2 + ((n * (n + 1) / 2) * m) - m << "\n";
	}
	return 0;
}
```





## 要点

结论推广