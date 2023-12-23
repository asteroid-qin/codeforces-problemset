# B. [Optimal Reduction](https://codeforces.com/problemset/problem/1713/B)

## 问题描述

给定长度n的数组a，确保在数组a的所有排列中，a的价值最小。a的价值定义为：执行区间值-1操作，使得a变为全0数组的最小操作数。



## 问题思路

倒着思考：

显然，如果a是顺序或者倒序，a的价值是最小的，并且为数组a的最大值。



所以，我们只需要计算给定的数组a的价值，判断是否大于等于即可。



那么如何线性计算最大价值呢？可以从最大值开始，找左右的最小值。



发现结论：最大值必须是峰顶，左右则是单调递减。否则会出现断层，绝对劣于顺序排列。



问题变为了：判断数组是否先增后减。



## 实现代码

```c++
#include<iostream>


int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int mx = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			mx = std::max(mx, a[i]);
		}
		std::string ans = "YES\n";
		
		for(int i = 0; i < n; i++) {
			if(mx == a[i]) {
				int j = i;
				while(j - 1 >= 0 && a[j] >= a[j - 1]) j--;
				
				if(j - 1 >= 0) {
					ans = "NO\n";
					break;
				}				

				j = i;
				while(j + 1 < n && a[j] >= a[j + 1]) j++;
				
				if(j + 1 < n) {
					ans = "NO\n";
				}
				break;
			}
		}
		
		std::cout << ans;
	}
	return 0;
}
```





## 要点

倒着思考，先思考最优解，然后尝试从最优解开始扩展。