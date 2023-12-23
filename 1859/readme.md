# A. [United We Stand](https://codeforces.com/problemset/problem/1859/A)

## 问题描述

给一个长度n的数组a，要求分成两个非空数组b、c，并且满足b中任意元素不被c中任意元素整除。



## 解决思路

b不被c整除很简单，只要c>b即可。

我们可以找到a的最大值，并计算它出现的次数。

如果次数等于n，也就是如论如何都无法满足题目要求。

否则，把最大值全分给数组c，其余的给b，这样就满足题目要求。



## 实现代码

```c++
#include<iostream>

int t, n, a[100];
void slv() {
	std::cin >> n;
	
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == mx) {
			cnt++;
		}
	}
	
	if(cnt == n) {
		std::cout << "-1\n";
		return;
	} 
	
	std::cout << n - cnt << " " << cnt << "\n";
	for(int i = 0; i < n; i++) {
		if(a[i] != mx) std::cout << a[i] << " ";
	}
	std::cout << "\n";
	for(int i = 0; i < cnt; i++) {
		std::cout << mx << " ";
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

很少的一点数论



# B. [Olya and Game with Arrays](https://codeforces.com/problemset/problem/1859/B)

## 问题描述

给n个数组，每个数组可以执行一次操作：把数组的元素放到另一个数组。数组只能被移出一次，但是能被放多次。求所有数组的最小值之和的最大值。



## 解决思路

所有数组的最小值换还是不换。



不换就是最小值，加上其他数组的次小值。



换了就是最小值，加上其他数组的次小值，最小值所在的次小值。显然这里应该选择最小的其他数组的次小值减去。



综上求最大值即可。



## 实现代码

```c++
#include<iostream>
#include<vector>

int t, n;
void slv() {
	std::cin >> n;
	std::vector<int> fir(n), sec(n);
	
	for(int i = 0; i < n; i++) {
		int m; std::cin >> m;
		int a = 1e9+7, b = 1e9+7;
		for(int j = 0; j < m; j++) {
			int x; std::cin >> x;
			if(x < a) {
				b = a;
				a = x;
			} else if(x == a) {
				b = x;
			} else if(x < b){
				b = x;
			}
		}
		fir[i] = a;
		sec[i] = b;
	}
	
	// 得到最小first 和 second 
	int min_fir = 1e9 + 7, min_sec= 1e9 +7;
	for(int i = 0; i < n; i++) {
		if(min_fir > fir[i]) min_fir = fir[i];
		if(min_sec > sec[i]) min_sec = sec[i]; 
	}
	
	// 处理sec
	long long sum_sec = 0;
	for(int i = 0; i < n; i++) {
		sum_sec += sec[i];
	} 
	
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(min_fir != fir[i]) continue;
		
		// 处理不移动 
		ans = std::max(ans, fir[i] + sum_sec - sec[i]);
		
		// 处理移动	
		ans = std::max(ans, fir[i] + sum_sec - min_sec);
	} 
		
	std::cout << ans << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



这里是第二版，上面的代码可以优化

```c++
#include<iostream>
#include<vector>

int t, n;
void slv() {
	std::cin >> n;
	std::vector<int> fir(n), sec(n);
	
	for(int i = 0; i < n; i++) {
		int m; std::cin >> m;
		int a = 1e9+7, b = 1e9+7;
		for(int j = 0; j < m; j++) {
			int x; std::cin >> x;
			if(x < a) {
				b = a;
				a = x;
			} else if(x == a) {
				b = x;
			} else if(x < b){
				b = x;
			}
		}
		fir[i] = a;
		sec[i] = b;
	}
	
	// 得到最小first 和 second 
	int min_fir = 1e9 + 7, min_sec= 1e9 +7;
	for(int i = 0; i < n; i++) {
		if(min_fir > fir[i]) min_fir = fir[i];
		if(min_sec > sec[i]) min_sec = sec[i]; 
	}
	
	// 处理sec
	long long sum_sec = 0;
	for(int i = 0; i < n; i++) {
		sum_sec += sec[i];
	} 
	std::cout << min_fir + sum_sec - min_sec << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点

读题 贪心 问题合并
