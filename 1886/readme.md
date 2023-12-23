# A. [Sum of Three](https://codeforces.com/problemset/problem/1886/A)

## 问题描述

判断一个数能否被3个不同且不被3整除的数组成。



## 问题思路

如果数x被a+b+c组成，且a<b<c，那么：



不妨设a=1，b=2，只需要求c即可c=n-3。



假如n不是3的倍数，那么1 2  n-3

否则，1 4 n-5



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int b, c;
		if(n % 3 == 0) b = 4, c = n - 5;
		else b = 2, c = n - 3;
		
		if(b < c) {
			std::cout << "YES\n";			
			std::cout << 1 << " " << b << " " << c << "\n";
			continue;
		}
		
		std::cout << "NO\n";
				
	}
	return 0;
}
```



## 要点

大胆假设