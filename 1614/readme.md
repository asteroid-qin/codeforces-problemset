# A. [Divan and a Store](https://codeforces.com/problemset/problem/1614/A)

## 问题描述

给个长度n的整数数组a，找到k个元素，使得和不超过k，且选中的元素都满足：$$l \leq a_i \leq r $$。



## 问题思路

贪心的想，排序后从小到大选择在范围内的数即可。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int t, n, l, r, a[101], k;
void slv() {
	std::cin >> n >> l >> r >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a+n);

	int cnt = 0;
	for(int i = 0; i < n && a[i] <= k; i++) {
		if(l <= a[i] && a[i] <= r) {
			cnt++;
			k -= a[i];
		}
	}
	std::cout << cnt << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```





## 要点

贪心



# B. [Divan and a New Project](https://codeforces.com/problemset/problem/1614/B)

## 问题描述



## 问题思路





## 实现代码

```c++

```





## 要点

