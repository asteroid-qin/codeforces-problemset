# B. [Balanced Array](https://codeforces.com/problemset/problem/1343/B)

## 问题描述

给定偶数n，要求构造长度n的数组a，满足：

1. 前n/2个元素都是偶数
2. 后n/2个元素都是奇数
3. a中所有元素都不同
4. 前n/2个元素的和与后n/2个元素的相同



## 问题思路

首先要确认：什么时候答案会不存在。

注意到前n/2个元素的和总为偶数，而n/2个元素的和不一定是奇数：也就是 n/2必须是偶数才行，偶数个奇数相加才能得到偶数。



因此：n必须被4整除。



那么有：

2 4 6 8 ... n

1 3 5 7 ... n-1



上面有n/2个偶数，下面有n/2个奇数，而且所有元素都不同。现在只需要满足：第四条约束即可。

注意到：上面的元素比对位的下面的元素的值要多个1，和自然比下面的要多个n/2。

因此只需要在下面元素的最后一位元素上加个2k即可。



总结：

循环i 从2到n，每次输出i，然后 i+2。

循环i 从1到n，每次输出i，然后 i+2，如果i是n-1，那么输出 i + n/2



## 实现代码

```c++
#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		if(n%4 != 0) {
			std::cout << "NO\n";
			continue;
		} 
		std::cout << "YES\n";
		for(int i = 2; i <= n; i+=2) std::cout << i << " ";
		
		for(int i = 1; i <= n; i+=2) {
			if(i != n-1) std::cout << i << " ";
			else std::cout << i + n / 2 << " ";
		}
		
		std::cout << "\n";
	}
	return 0;
}
```



## 要点

偶数个奇数相加才能得到偶数