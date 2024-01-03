# A. [Free Ice Cream](https://codeforces.com/problemset/problem/686/A)

## 问题描述

模拟题目。给定长度n的数组a，和初始值x，要求循环一遍a：



初始cnt=0。如果 x + a[i] >= 0，那么x变为x + a[i]，否则cnt++。



最后要求输出x和cnt。



## 问题思路

很简单的模拟题目，按照题目要求做就行，唯一需要注意的是数据范围。



## 实现代码

```c++
#include<iostream>

int n;
long long x;
int main() {
	
	std::cin >> n >> x;
	
	int cnt = 0, val;
	char opt;
	
	for(int i = 0; i < n; i++) {
		std::cin >> opt >> val;
		if(opt == '+') x += val;
		else {
			if(x - val < 0) {
				cnt++;
			} else {
				x -= val;
			}
		}
	}
	
	std::cout << x << " " << cnt << "\n";	
	return 0;
}
```



## 要点

模拟