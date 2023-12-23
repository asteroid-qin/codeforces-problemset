# A. [Two 0-1 Sequences](https://codeforces.com/problemset/problem/1704/A)

## 问题描述

分别给长度n和m的01字符串a和b，可以执行任意次操作：删除a的第一个元素或者第二个元素。现在判断能否让a等于b。



## 问题思路

因为只能删除第一个或者第二个，所以当n=m+1时，删除哪一个变成了问题，并且得到了一个结论：



a必须倒着至少和b匹配m-1位。



至于剩下的一位，只要a前面的字符串中存在即可。



## 实现代码

```c++
#include<iostream>

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::string a, b;
		std::cin >> n >> m >> a >> b;
		
		
		bool fa = true, fb = false;
		for(int i = m - 1; i > 0; i--) {
			if(a[n-1-m+1+i] != b[i]) {
				fa = false;
				break;
			}
		}
		
		// 尝试让
		for(int i = 0; i < n - m + 1; i++) {
			// [p, n-1]   n-p+1=m   
			if(a[i] == b[0]) {
				fb = true;
				break;
			}
		} 
		
		if(fa && fb) std::cout << "YES\n";	
		else  std::cout << "NO\n";	
	}
	return 0;
}
```





## 要点

考虑极端情况：n=m，n=m+1时，瞬间得到重要信息。