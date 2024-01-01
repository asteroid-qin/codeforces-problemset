# A. [An abandoned sentiment from past](https://codeforces.com/problemset/problem/814/A)

## 问题描述

给定长度n的整数数组a和长度k的数组b，满足：

1. a中有k个0



现在可以使用b中的元素，替换a中的0（b中每个元素只能使用一次），现在问能否得到新的a（不含0），满足：

1. a不是递增序列



## 问题思路

贪心的，可以对b递减排序，然后a中第1个0使用b中第1个元素（最大的），第2个0使用b中第2个元素（次大的）。



但是实际上，我们只需要判断a是否是递增序列即可，不关心a最终的样子。因此，可以对b分类讨论：

1. b中所有元素相同。此时循环a，如果a[i]=0，那么令a[i] = b[0]，然后判断a[i-1] <= a[i] 即可。
2. b中存在元素不同。因为不同，所以必然有b[i] < b[j]，且 k >= 2。所以我们只需要把这个b[i] 和 b[j]放在a的0上，使得a出现一个逆序对即可。



总结：

循环b，判断b[i] = b[i-1]来得到b中所有元素是否相同。

如果相同，循环a，a[i]=0时给个默认值，再通过a[i-1] 和 a[i] 的单调性

如果不同，直接输出 YES即可



## 实现代码

```c++
#include<iostream>

int n, m, a[101], b[101]; 
int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	for(int i = 0; i < m; i++) std::cin >> b[i];
	
	bool eq = true;
	for(int i = 1; i < m; i++) {
		if(b[i] != b[i-1]) {
			eq = false;
			break;
		}
	}
		
	if(!eq) {
		std::cout << "YES\n";
		return 0;
	}	
	
	bool np = true;
    if(a[0]==0) a[0] = b[0];
	for(int i = 1; i < n; i++) {
		if(a[i] == 0) a[i] = b[0];
		
		if(a[i-1] > a[i]) {
			np = false;
			break;
		}
	}
	
	if(np) std::cout << "NO\n";
	else std::cout << "YES\n";
		
	return 0;
}
```



## 要点

对b分类讨论