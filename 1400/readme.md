# A. [String Similarity](https://codeforces.com/problemset/problem/1400/A)

## 问题描述

给定长度为n*2 - 1的01数组a，要求构造一个长度n的01数组b，b满足与a中所有长度为n的连续子数组相似。



相似定义为：存在一个下标i，使得两数组下标处的值相等。

## 问题思路

可以把a写作：

a[1] a[2] a[3] ... a[n]

a[2] a[3] a[4] ... a[n+1]

a[3] a[4] a[5] ... a[n+2]

...

a[n] a[n+1] a[n+2] ... a[2*n-1]



如此得到n*n的二维数组。



尝试从到到尾选择b的值：

显然b[1] = a[i] ， 这样第一行就解决掉了

第二行，如果让b[2] = a[2]，那么它只能和第一行的匹配，所以让它等于a[3]，第二行被解决掉了。

第三行，同理让b[3] = a[5]，解决第三行。

...



到这里，发现一个规律：让b[i] = a[i*2-1]就可以解决i行。当i从1取到n的时候，就能得到符合题意的数组b。



总结：从1到n*2-1输出a[i]，每次i + 2。



## 实现代码

```c++
#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		char ch;
		std::string s;
		
		for(int i = 1; i <= 2*n-1; i++) {
			std::cin >> ch;
			if(i&1) s += ch;
		} 
		
		std::cout << s << "\n";
	}
	return 0;
} 
```



## 要点

找规律