# B. [Two Out of Three](https://codeforces.com/problemset/problem/1894/B)

## 问题描述

给长度n的数组a，要求构造仅有1、2、3构成的长度n的数组b。三个条件恰好满足两个。


$$
a_i=a_j, b_i=1, b_j=2. \\
a_i=a_j, b_i=1, b_j=3. \\
a_i=a_j, b_i=2, b_j=3.
$$


## 问题思路

如果数组a每个元素都不相等，三个条件都无法满足。

如果有一对相等，三个条件只能满足其中一个。

如果有两对以上（两对可以合入）：

3对，6个坐标其中

第一对是：1 2

第二对是：1 3 

第三队是：1 2  或者 1 3 或者 2 3



发现一个问题，我需要满足2个条件，而任意两个条件就包含了1、2、3。也就是无论如何，只要数组a中有超过三个数相等，那么绝不能构造出3个不相等的值。

也就是必须至少得有2种不同的值，每种不超过2种选法。



问题变成了，对a[i]分组，把a[i]相等的坐标放在一组。保证至少有2组，第一组有且仅有1和2，第二组有且仅有1和3，其他组都是1。



## 实现代码

```c++
#include<iostream>
#include<vector>

std::vector<int> vec[101];
int t, n, a[101], b[101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= 100; i++) {
			vec[i].clear();
		}
		
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			vec[a[i]].push_back(i);
			b[i] = 1;
		}
		
		
		int p = 1, cnt = 0;
		// 先找第一组
		for(; p <= 100; p++) {
			if(vec[p].size() < 2) {
				continue;
			}
			
			b[vec[p][0]] = 1;
			for(int i = 1; i < vec[p].size(); i++) {
				b[vec[p][i]] = 2;
			}
			cnt++; p++;
			break;
		}
		
		// 再找第二组 
		for(; p <= 100; p++) {
			if(vec[p].size() < 2) {
				continue;
			}
			
			b[vec[p][0]] = 1;
			for(int i = 1; i < vec[p].size(); i++) {
				b[vec[p][i]] = 3;
			}
			cnt++; p++;
			break;
		}
		
		if(cnt == 2) {
			for(int i = 0; i < n; i++) {
				std::cout << b[i] << " ";	
			}
			std::cout << "\n";
			continue;
		}
		 
		std::cout << "-1\n";
	}
	return 0;
}
```





## 要点

分组