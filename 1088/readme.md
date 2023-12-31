# A. [Ehab and another construction problem](https://codeforces.com/problemset/problem/1088/A)

## 问题描述

给定整数x，要求找到两个整数：a和b，满足：

1. 1 <= a,  b <= x
2. a 被 b 整除
3. a * b > x
4. a / b < x



## 问题思路

当x=1时，答案不存在（测试用例也给了）

当x >1时，可以让a=b=x，这样：

1. 满足
2. x肯定被x整除，满足
3. x>1 => x*x > x => a * b > x，满足
4. x/x=1 < x，满足



总结：

如果x=1，输出-1

否则，输出x x

## 实现代码

```c++
#include<iostream>

int x;
int main(){
	std::cin >> x;
	if(x == 1) {
		std::cout << "-1\n";
	} else {
		std::cout << x << " " << x << "\n";
	}
	return 0;
} 
```



## 要点

贪心