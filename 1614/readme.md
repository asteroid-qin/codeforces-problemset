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

给定长度n的数组a（a[i] >= 0），要求构造长度n+1的数组b，使得 

1. a[i] *|b[i] - b[0] | * 2 的和最小
2. b[i] 各不相等



## 问题思路

不妨令b[0] = 0，接下来只需要考虑1-n的下标。



显然a[i]愈大，那它就应该离0越近，这样和才会尽可能小。

因此可以对a[i]排序，从大到小2个2个地放在0的上边和下边即可，如果n是奇数，会多出1个，那它的坐标只能是n/2+1。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

struct Node{
	int id, val;
	bool operator<(const Node& n) const {
		if(val == n.val) return id < n.id;
		return val > n.val;
	} 
} a[200001];
int t, n, ans[200001];


void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i].val;
		a[i].id = i;
	}	
	std::sort(a+1, a+1+n);
	
	ans[0] = 0;
	
	int m = n / 2;
	long long sum = 0;
	
	for(int i = 1; i <= m; i++) {
		ans[a[i*2-1].id] = i;
		ans[a[i*2].id] = -i;
		
		sum += (long long) (a[i*2-1].val + a[i*2].val) * i;
	}
	
	if(n&1) {
		ans[a[n].id] = m + 1;
		sum += (long long)a[n].val * (m + 1);
	}
	
	std::cout << sum*2 << "\n";
	for(int i = 0; i <= n; i++) {
		std::cout << ans[i] << " ";
	}
	
	std::cout << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```





## 要点

贪心：a[i]愈大，那它就应该离0越近
