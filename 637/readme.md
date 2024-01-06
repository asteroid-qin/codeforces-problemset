# A. [Voting for Photos](https://codeforces.com/problemset/problem/637/A)

## 问题描述

给定长度n的数组a，记a的元素的出现次数是cnt，要求找到第一个达到（从前往后）cnt的a[i]，并输出。



## 问题思路

循环一遍a，使用map计数，对a[i]计数。

再循环一遍map，求出现次数的最大值，得到cnt。

最后循环一遍a，使用map计数，如果a[i]==cnt，那么输出a[i]作为答案



## 实现代码

```c++
#include<iostream>
#include<map>

int n, a[1000];

int main() {
	std::cin >> n;
	
	std::map<int, int> mp;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mp[a[i]]++;
	}
	
	int cnt = 0;
	for(auto it : mp) {
		cnt = std::max(cnt, it.second);
	}	
	
	mp.clear();
	for(int i = 0; i < n; i++) {
		mp[a[i]]++;
		if(mp[a[i]] == cnt) {
			std::cout << a[i] << "\n";
			return 0;
		}
	}
	return 0;
}
```



## 要点

模拟