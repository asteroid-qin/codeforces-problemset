# A. [Ichihime and Triangle](https://codeforces.com/problemset/problem/1337/A)

## 问题描述

给定整数a、b、c、d，满足 a <= b <= c <= d，要求构造x 、y、z，满足：

1. a <= x <= b
2. b <= y <= c
3. c <= z <= d
4. x + y > z且 x +z >y且y+z >x

## 问题思路

要满足三角等式，可以尝试让x=y=z，也就是等边三角形。



但是这道题目限制了x、y、z的范围，因此只能取等腰三角形：

让x = b，y和z =c即可。（不使用 b b c是因为b + b 不一定大于c）



首先这样满足1、2、3点。



至于第四点，把b、c之间的关系带入，发现也是满足的。



总结：

输出： b c c

## 实现代码

```c++
#include<iostream>

int t, a, b, c, d;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b >> c >> d;
		std::cout << b << " " << c << " " << c<<"\n";
		
	}
	return 0;
} 
```



## 要点

贪心