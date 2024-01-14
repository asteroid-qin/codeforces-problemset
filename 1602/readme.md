# B. [Divine Array](https://codeforces.com/problemset/problem/1602/B)

## 问题描述

给定长度n的数组a，第k次会执行k次变换，每次变换都是把a[i]替换为数组a中a[i]出现的次数。



现在给出q次查询，给定x和k，要求第k次变化 a[x] 的值



## 问题思路

题目给了1 <= a[i] <= n，看测试用例会发现：在变化几次后，所有的值就不动了。



具体多少次呢？我不知道，但是显然是在题目允许之内的，于是我写了下面这个丑陋的代码：

用mx来表示第mx次及以后，变化效果相同，于是 k = min(k, k)，

然后对q次查询排序，使得q[i].k < q[i + 1].k，然后再双指针执行q[i].k次，再把当前q[i].x的结果赋给 ans[q[i].id]



这么写是可以的，而且还剩下一堆空间，但是代码量实在是太多了。即使不知道如何证明 mx = log(n)，但也该意识到 mx <= n，所以可以先预处理，后面只需要查表。



因为1 <= n <= 2000，所以绝对是没问题的。当然，我下面的写法，针对n <= 100000也有效，这次就当自己练练手。



总之，数据范围真的很重要。



## 实现代码

```c++
#include<iostream>
#include<algorithm>

struct Node{
	int id, x, k;
	
	bool operator<(const Node& n) {
		if(k == n.k) return id < n.id;
		return k < n.k;
	}
} q[100000];
int t, n, a[2001], b[2001], c[2001], m, cnt[2001], ans[100000];
int k, x;

void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	
	int mx = 0;
	while(true) {
		for(int i = 1; i <= n; i++) {
			cnt[i] = 0;
		}
		
		for(int i = 1; i <= n; i++) {
			cnt[b[i]]++;
		}
		
		for(int i = 1; i <= n; i++) {
			c[i] = cnt[b[i]];
		}
		
		bool eq = true;
		for(int i = 1; i <= n; i++) {
			if(b[i] != c[i]) {
				eq = false;
			}
			b[i] = c[i];
		}
		
		if(eq) break;
		mx++;		
	}
	
	for(int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		std::cin >> q[i].x >> q[i].k;
		q[i].id = i;
		q[i].k = std::min(q[i].k, mx);
	}
	
	std::sort(q, q+m);
	
	for(int i = 0, j = 0; i < m; i++) {
		while(j < q[i].k) {
			for(int p = 1; p <= n; p++) {
				cnt[p] = 0;
			}
			
			for(int p = 1; p <= n; p++) {
				cnt[b[p]]++;
			}
			
			for(int p = 1; p <= n; p++) {
				c[p] = cnt[b[p]];
			}
			
			for(int p = 1; p <= n; p++) {
				b[p] = c[p];
			}
			
			j++;
		}
		
		ans[q[i].id] = b[q[i].x];
	}
	
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << "\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	
	return 0;
}
```



## 要点

意识到和上次不同的变化次数是有限制的

