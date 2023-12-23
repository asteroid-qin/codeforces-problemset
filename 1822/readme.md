# D. [Super-Permutation](https://codeforces.com/problemset/problem/1822/D)

## 问题描述：


$$
定义一个a_i和一个b_i，并且满足b_i=(a_1+a_2+ ... + a_i) % n，如果
$$




## 问题思路：

首先a1必然是n，因为如果存在ak=n，那么bk=bk-1这产生矛盾。

其次，n不能是奇数，因为奇数求和会被n整除，这与b1矛盾。

最后找到一个n为偶数的答案：

n，1，n-2，3，n-4，...，n-1，2



## 实现代码：

```c++
#include<iostream>

void slv() {
	int n;
	std::cin >> n;
	if(n&1) {
		std::cout << "-1\n";
		return;
	} 
	std::cout << n;
	for(int p = 1, q = n - 2; p < n; p += 2, q -= 2) {
		std::cout << " " << p;
		if(q > 0) std::cout << " " <<  q; 
	}
	
	std::cout << "\n";
}
int main() {
	int t;
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点：

虽然证明n为偶数才有解比较简单，但是想要构造排列并不简单，纯粹构造
