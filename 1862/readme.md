# B.[Sequence Game](https://codeforces.com/problemset/problem/1862/B)

## 问题描述


$$
有长度m数组a，取它的首元素，得到数组b（a_1=b_1）。循环数组a，如果a_{i-1} \leq a_i，那么把a_i放入b中，现在给出数组b。求原数组a。
$$


## 问题思路


$$
从0开始循环b，如果b_{i-1} \leq b_i，那么仅仅只需要输出b_i。否则输出b_i \ b_i。
$$


## 实现代码

```c++
#include<iostream>

int t, n, a[400002], p;

void slv() {
	std::cin >> n;
	p = 0;
	
	for(int i = 0, x, pre; i < n; i++) {
		std::cin >> x;
		if(i == 0 || pre <= x) {
			a[p++] = x;
		} else {
			a[p++] = x; a[p++] = x;
		}
		pre = x;
	}
	
	std::cout << p << "\n";
	for(int i = 0; i < p; i++) {
		std::cout << a[i] << " ";
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

找规律

