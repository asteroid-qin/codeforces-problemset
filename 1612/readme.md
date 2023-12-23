# A. [Distance](https://codeforces.com/problemset/problem/1612/A)

## 问题描述

定义两个点的距离是横坐标和纵坐标的绝对值的和。现在给出两点A(0, 0)，B(x, y)，求C使得：

1. d(A,C)=d(A,B)/2
2. d(B,C)=d(A,B)/2



## 问题思路

注意：d(A,B) 的距离是定死的。



现在考虑x+y是奇数还是偶数？如果是奇数，那么(x+y)/2因为不会取整，所以C的坐标之和必须是个小数，和题目不符直接舍去。

所以，x+y就是偶数：2k



在第一点得到，c的坐标是(t, k-t)

在第二点得到，令x <= y，t=0，则有等式：

x-0+y-k=k => x+y=2k 显然恒成立。



综上：

1. x+y 是奇数输出-1 -1
2. x <= y ，则输出0  (x+y)/2
3. x > y，则输出 (x+y)/2 0



## 实现代码

```c++
#include<iostream>
int t, a, b;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		if( (a + b) & 1) {
			std::cout << "-1\n";
			continue;
		}
		if(a <= b) {
			std::cout << 0 << " " << (a+b)/2 << "\n";
		} else {
			std::cout << (a+b)/2 << " " << 0 << "\n";
		}
	}
	return 0;
}
```





## 要点

公式







# B. [Special Permutation](https://codeforces.com/problemset/problem/1612/B)

## 问题描述

给定偶数n和a、b。要求构造一个长度n的1-n的全排列。其前半部分的最小值是a，后半部分的最大值是b。



## 问题思路

贪心地想：既然最小值是a，那么a+1 ... a+2 ... 直到a+n/2都是可以的，也就是：比a大的数都可以往里面放。既然如此，那就把最大值往里面放：n n-1 ... 直到n/2。



显然，a最大取值是n/2。

现在构造好左半部分，右边部分使用剩下的即可，只要保证b的最小值是n/2。



## 实现代码

```c++
#include<iostream>

bool sel[101];
int ans[101];

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, a, b;
		std::cin >> n >> a  >>  b;

		int k = n / 2;
		for(int i = 1; i <= n; i++) {
			sel[i] = 0;
		}
		
		int p = 0;
		ans[++p] = a;
		sel[a] = sel[b] = 1;
				
		for(int i = n; i >= 1 && p <= k; i--) {
			if(sel[i]) continue;
			sel[i] = 1;
			ans[++p] = i;
		}
		
		ans[++p] = b;
		for(int i = 1; i <= n; i++) {
			if(sel[i]) continue;
			ans[++p] = i;
		}
		
		int mi = 1e9, mx = 0;
		for(int i = 1; i <= k; i++) {
			mi = std::min(mi, ans[i]);
			mx = std::max(mx, ans[i+k]);
		}
		
		if(mi != a || mx != b) {
			std::cout << "-1\n";
			continue;
		} 
		
		for(int i = 1; i <= n; i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
```



## 要点

贪心