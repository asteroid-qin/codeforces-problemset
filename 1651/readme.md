# B. [Prove Him Wrong](https://codeforces.com/problemset/problem/1651/B)

## 问题描述

是否构造一个长度n的数组，满足：任意两个索引i, j上的值变为abs(a[i]-a[j])后，其和不递减。



## 问题思路

令a[i] > a[j]，则abs(a[i] - a[j]) = a[i] - a[j]



因为只有a[i]和a[j]的值变化，做差得到:

a[i] + a[j] - a[i] + a[j] - a[i] + a[j] = 3 * a[j] - a[i]



要满足不递减，也就是对于任意的i，j   a[i] >= 3 * a[j]。



可以让a是一个单调递减数组：

如果a[i] >= 3* a[j]，那自然a[i] >= 3 * a[j+1] >= 3* a[j+2]  >= ...



因此只需要a[i] >= 3*a[i+1] 即可。



换句话说：打印：1 3 9 .. 



因为a[i] 不能超过1e9，所以n满足  3^(n-1) <= 1e9 ，n <= 1+ (int) log3 1e9。



## 实现代码

```c++
#include<iostream>
#include<cmath>

int t, n;
int main(){ 
	int N = (int) (log(1e9) / log(3)) + 1;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n > N) {
			std::cout << "NO\n";
			continue;
		}
		
		std::cout << "YES\n";
		int p = 1;
		for(int i = 1; i <= n; i++) {
			std::cout << p << " ";
			p *= 3;
		}
		std::cout << "\n"; 
	}
	return 0;
} 
```



## 要点

公式计算