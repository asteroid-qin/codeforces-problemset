# B. [Aleksa and Stack](https://codeforces.com/problemset/problem/1878/B)

## 问题描述

要求构造一个长度n的正整数数组a，a满足严格递增和$$3 \cdot a_{i+2} \not\equiv 0 \pmod {a_i + a_{i+1}}$$



## 问题思路

可以令a1是1，a2是2，则a3是(a1+a2)*3+1。



这样递推下去绝对使得不被整除。但是这里n给的值比较大，数据会爆，所以不能这样。



那么考虑让a3=a1+a2。因为a1被



3ai+2 = kai+kai+1+1or2

当k=1时，3ai+2=ai+ai+1+1 => ai+2=ai+ai+1-1/3   也就是ai+2必然小于ai或者ai+1，不满足题意，舍去。

当k=2时，3ai+2=2ai+2ai+1+1=>ai+2=2ai+2ai+1/3 依旧不行，舍去

当k=3时，3ai+2=3(ai+ai+1)+1 => ai+2 = 3ai+3ai+1+1/3，非整数，舍去。

当k=4时，3ai+2=4(ai+ai+1)+1 => ai+2 = (4ai+4ai+1+1)/3

当a1 = 1，a2=2时，a3=12，否

​	a1 = 1，a2=4时，a3=7，满足题意



大胆猜测，找到规律：那就是：$$a_i=3 \cdot i  - 2$$



因为

ai+2=3n+7，3ai+2=9n+21

ai+ai+1=3n+1+3n+4=6n+5

6n+5+3n+16/6n+5=1+3n+16/6n+5



n=1时，19/11否

n=2时，22/17否

n=3时，25/23否

n=4时，28/29否

后续分母大于分子，所以小于1不被正常，证毕。

## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << 3* i - 2<< " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
```



## 要点

数学推导