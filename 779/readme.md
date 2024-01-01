# A. [Pupils Redistribution](https://codeforces.com/problemset/problem/779/A)

## 问题描述

给定长度n的整数数组a和b（a和b中只有1、2、3、4、5），可以选择a中一个元素与b中一个元素交换。现在问：



使得a和b的每个值出现的次数相等的最小交换次数



## 问题思路

计a和b两边1出现的个数分别为c[1]、d[1]

计a和b两边2出现的个数分别为c[2]、d[2]

计a和b两边3出现的个数分别为c[3]、d[3]

计a和b两边4出现的个数分别为c[4]、d[4]

计a和b两边5出现的个数分别为c[5]、d[5]



显然c[i]+d[i] 一定是偶数。

如果c[i]+d[i]=0，那就是不需要交换，跳过。

如果(c[i]+d[i])/2=k，那么需要交换abs(k- c[i])次。



所以总交换次数是：abs((c[i]+d[i])/2 - a[i]) 的和，i从1到5.

又注意到这时最小和，所以每次交换都可以处理好2个元素，所以最终结果需要再/2。



总结：

输出：abs((c[i]+d[i])/2 - a[i]) 的和 / 2，i从1到5.



## 实现代码

```c++
#include<iostream>

int n, c[6], d[6];
int main() {
	std::cin >> n;
	for(int i = 1; i <= 5; i++) c[i] = d[i] = 0;
	int x;
	
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		c[x]++;		
	}
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		d[x]++;
	}
	
	int ans = 0;
	for(int i = 1; i <= 5; i++) {
		int sum = c[i] + d[i];
		if(sum & 1) {
			std::cout << "-1\n";
			return 0;
		}
		ans += abs(sum / 2 - c[i]);
	}
	
	std::cout << ans / 2 << "\n";
	return 0;
} 
```



## 要点

模拟