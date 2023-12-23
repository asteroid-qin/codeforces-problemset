# B. [Scenes From a Memory](https://codeforces.com/problemset/problem/1562/B)

## 问题描述

输入一个不含0的十进制数，尝试删掉一些数位得到一个新的数：不是质数。



## 问题思路

首先偶数一定不是质数，问题变为了k中是否包含任意一个偶数：2 4 6 8？

当然1也可以。

如果包含，那么删到只剩这其中一个即可。

否则，这个数就是由3 5 7 9组成，其中9也不是质数去掉。



也就是这个数仅有3 5 7 组成。

继续分类：任意一位数出现两及以上次，比如33、55、77.这显然也是可以的。

剩下的就只有：

3 5 7 （不符合题意舍去）

35 37 53 57 73 75		（35 57 75都可以）

357 375 353 573 735 753 （三个比如有57 75，直接过）



所以只需要讨论是否包含5和7。包含就输出57或者75.

否则就是只有5或者只有7或者两个都没有（舍去）

显然最后一种情况只有：35.



## 实现代码

```c++
#include<iostream>
#include<vector>

int t, n;
std::string s;

int one[] = {1, 4, 6, 8, 9};
int two[] = {2, 3, 5, 7};

void slv() {
	std::cin >> n >> s;
	std::vector<int> cnt(10, 0);
	for(char ch : s) cnt[ch-'0']++;
	
	// 一个数 
	for(int i = 0; i < 5; i++) {
		if(cnt[one[i]] != 0) {
			std::cout << "1\n" << one[i] << "\n";
			return;
		}
	}	
	// 两个数 
	for(int i = 0; i < 4; i++) {
		if(cnt[two[i]] > 1) {
			std::cout << "2\n";
			std::cout << two[i] << two[i] << "\n";
			return;
		}
	}
	
	// 现在开始长度为2-4
	// 长度2（因为都是奇数，长度2不能删掉）
	if(n == 2) {
		std::cout << n << "\n" << s << "\n";
		return;
	} 
	
	// 长度3：235，237，257，357.
	// 其中包含2的必然有25 52 或者 27 72 。长度4在这步也被解决。 
	if(cnt[2] && cnt[5]) {
		std::cout << "2\n"; 
		for(char ch : s) {
			if(ch != '5' && ch != '2') continue;
			std::cout << ch;
		}
		std::cout << "\n";
		return;
	}
	
	if(cnt[2] && cnt[7]) {
		std::cout << "2\n"; 
		for(char ch : s) {
			if(ch != '7' && ch != '2') continue;
			std::cout << ch;
		}
		std::cout << "\n";
		return;
	}
	// 不包含2的长度为3的只有 3 5 7。因为57 75 
	std::cout << "2\n"; 
	for(char ch : s) {
		if(ch != '5' && ch != '7') continue;
		std::cout << ch;
	}
	std::cout << "\n";
}
int main() {
	std::cin >> t;
	
	
	while(t--) {
		slv(); 
	}
	return 0;
} 
```



## 要点

分类讨论（又臭又长）