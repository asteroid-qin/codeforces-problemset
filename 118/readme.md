# B. [Present from Lena](https://codeforces.com/problemset/problem/118/B)

## 问题描述

模拟题目，给定整数n，要求输出一个菱形。



例如：

n=2

```
    0
  0 1 0
0 1 2 1 0
  0 1 0
    0
```

n=3

```
      0
    0 1 0
  0 1 2 1 0
0 1 2 3 2 1 0
  0 1 2 1 0
    0 1 0
      0
```



## 问题思路

显然，我们需要计算这个菱形的长和宽。

长和宽都是：2*n+1



因此我们可以循环i和j，i和j的范围都在[1, 2*n+1]。



现在需要知道i和j距离菱形中心的距离：因为菱形的值是由距离来决定的。

显然中心点的坐标是：n+1, n+1。



记dis为点： i，j 到 点：n+1，n+1的距离。dis = abs(n+1-i) + abs(n+1-j)。

则 a[i] [j] = n - dis，如果a[i] [j] < 0 ，那么就需要替换为空格



总结：

双重for循环i和j，i和j的范围在[1, 2*n+1]。

内层for循环，记 x = n -  abs(n+1-i) - abs(n+1-j)：

​	如果x < 0，输出" "

​	否则，输出 x



注意！题目要求还挺多，尽管看上去一样，但是不能多出多余的空格。所以需要对x或者" "后面是否需要输出" "做特判。

## 实现代码

```c++
#include<iostream>

int n;
int main() {
	std::cin >> n;
	for(int i = 1; i <= 2*n +1; i++) {
		for(int j = 1; j <= 2*n+1; j++) {
			int x = n - abs(n+1-i) - abs(n+1-j);
			
			if(x >= 0) {
				std::cout << x;
			} else {
				std::cout << " ";
			}
			
			if(x == 0 && j > n) {
				break;
			} else {
				std::cout << " ";
			}
		}
		
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

模拟