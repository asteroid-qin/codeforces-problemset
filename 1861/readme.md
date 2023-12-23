# A. [Prime Deletion](https://codeforces.com/problemset/problem/1861/A)

## 问题描述

给一个长度9的字符串（由1-9组成且每个数只出现一次）。可以执行至少0次操作：选择一个数然后删掉它，如果字符串长度大于>2。现在判断是否可以让这个字符串变为一个质数？



## 问题思路

任意位置可以删，那么可以当只剩下2个数。现在讨论：2位数中是质数的有：13、19、23、29、31、37、41、43、47、53、59、61、67、71、73、79、83、89、97。因此只需要判断1-9后面是否存在可以组成质数的个位数即可。



继续观察发现：有13和31这两个质数，显然答案必有解。只需要判断给的字符串是1在3的前面还是后面即可。



用代码实现，只需要排除1、3以外的数直接输出即可。

## 实现代码

```c++
#include<iostream>

std::string s;
int main() {
	int t; std::cin >> t;
	while(t--) {
		std::cin >> s;
		for(char ch : s) {
			if(ch == '1' || ch == '3') std::cout << ch;
		}
		std::cout << "\n";
	}
	return 0;
} 
```



## 要点

找规律



# B. [Two Binary Strings](https://codeforces.com/problemset/problem/1861/B)

## 问题描述

给两个长度相等的01字符串，判断存在执行多次操作后两个字符串相等。每次操作可以任选其中一个字符串，再选择它的两个相等的字符的索引，然后把中间所有的字符变为索引处的字符。



注意，这两个字符串都是0开始1结束。



## 问题思路

没必要只操作a或者b，可以让a和b都朝着一个目的转换。

类似：0000...01...11111。

我们只需要知道一个索引，满足：$$a_i = b_i = 0 \ \and  a_{i+1}=b_{i+1} = 1$$

那就代表a和b可以相等！



## 实现代码

```c++
#include<iostream>

int main() {
	int t, n;
	std::string a, b, ans;
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		n = a.size();
		
		ans = "NO\n";
		for(int i = 0; i < n - 1; i++) {
			if(a[i] == b[i] && a[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1') {
				ans = "YES\n";
				break;
			}
		}
		
		std::cout << ans;
	}
	return 0;
} 
```



## 要点

找最简单的做法
