# A. [Constructive Problems](https://codeforces.com/problemset/problem/1905/A)

## 问题描述

给定整数n和m，描述一个n行m列的矩阵a。在矩阵a[i] [j] 中，如果a[i] [j] = 0，想让它变为1只有1种可能：

1. a[i+1] [j] = 1 或者 a[i-1] [j] = 1
2. a[i] [j+1] = 1 或者 a[i] [j-1] = 1



定义 p 为 a中初始值为1的单元格个数。如果p=0，那么a初始值全都是0。



现在，想让a的所有值都是1，问p最少应该取几？



## 问题思路

假设n=m：

为了让p的值最小，我们可以在对角线上划一道：让对角线上的元素的值都是1。



显然，在下一刻对角线上的1会朝着下和上同时移动，最终让所有元素都等于1。



所以答案是n。



假设n != m：

依旧是从对角线上走，但是到达底部时，还会剩下一些距离，此时需要继续朝着对象上走。因此答案是max(n, m)



证明太难了，就不写了。



总结：输出n和m的最大值。



## 实现代码

```c++
#include<iostream>

int t, n, m;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		std::cout << std::max(n, m) << "\n";
	}
	
	return 0;
} 
```



## 要点

对角线上最优