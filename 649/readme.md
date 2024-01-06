# A. [Любимые числа Поликарпа](https://codeforces.com/problemset/problem/649/A)

## 问题描述

纯俄文，幸好有翻译软件。



给定长度n的整数数组a，要求找到一个最大值r（r是2的幂次方）：满足存在一个 a[i] & (r - 1)  == 0整除。



同时，输出a中被(1 << r)整除的元素的个数。



## 问题思路

模拟即可。



对于每个a[i]，想要求r很简单，可以用a[i] & (a[i]-1)来去掉a[i]在2进制下的最右边第一个1，这里记它为p，则r = a[i] - p。显然只需要求最大的r即可。



先循环一次a，找到一个最大的x：a[i] -(a[i] & (a[i]-1)) 。找不到默认x=1。

再循环一次a，输出a[i] % x == 0的数量



## 实现代码

```c++
#include<iostream>
#include<cmath>

int n, a[100];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int x = 1;
	for(int i = 0; i < n; i++) {
		int p = a[i] & (a[i] - 1);
		x = std::max(x, a[i] - p);
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % x == 0) cnt++;
	}
	
	std::cout << x << " " << cnt << "\n";
	return 0;
}
```



## 要点

模拟 、 二进制