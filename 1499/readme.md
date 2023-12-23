# A. [Domino on Windowsill](https://codeforces.com/problemset/problem/1499/A)

## 问题描述

给定2 * n 的数组，初始值全为0.给定k1和k2，可以分别为第一行和第二行设置k1和k2个1。现在问：



连续两个1的数量是否大于等于w 同时 连续两个0的数量是否大于等于b。（因为是二维数组，连续表示水平连续和竖直连续）

## 问题思路

贪心地做：

1 1 1 1 ... 0 0 0 .. 0 : 1 有k1个

11 ... 0 0  0 0 0 .. 0 : 1 有k2个



显然连续两个1的数量由第一行的值/2+第二行的值/2得到。

如果k1和k2都是奇数，那么可以再+1.

如此得到最大的连续两个1的数量，此时只要判断大于等于w即可。



同理，对于0，第一行是n-k1个，第二行是n-k2个，计算公式同上。

## 实现代码

```c++
#include<iostream>

int t, n, k1, k2, w, b;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k1 >> k2 >> w >> b;

		int max_w = k1 / 2 + k2 / 2;
		if( (k1 & 1) && (k2 & 1) ) max_w++;
		
		k1 = n - k1, k2 = n - k2;
		int max_b = k1 / 2 + k2 / 2;
		if( (k1 & 1) && (k2 & 1) ) max_b++;
		
		if(w <= max_w && b <= max_b)  {
			std::cout << "YES\n";
		}  else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
```



## 要点

贪心