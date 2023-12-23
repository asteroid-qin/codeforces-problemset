# A. [Digit Minimization](https://codeforces.com/problemset/problem/1684/A)

## 问题描述

输入一个由1-9组成的字符串s，每次**必须**交换两个索引上的字符，然后**必须**删除字符串最后的字符，删除操作会在字符串长度变为0时停止。



求最后的字符，最小可能是？



## 问题思路

都说了可以任意交换两个索引，直接把最小值放在最后，后面随便交换即可。



但是问题并没有这么简单，因为强制必须交换。当n为2时，答案必然是最后一位：s[1]。



当n=3时：

1. 第一步把最小字符放在第2位，去掉任意字符。
2. 第二步交换，保留住了最小字符



当n=4时：

1. 把最小字符放在第1位或者第3位，去掉任意字符
2. 问题变为n=3时的情况



到此结束，可以证明当n>2时，可以选到最小字符。否则，输出a[1]。



## 实现代码

```c++
#include<iostream>

int main() {
	std::string s;
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		int n = s.size();
		if(n == 2) std::cout << s[1] << "\n";
		else {
			char x = '9';
			for(char ch : s) x = std::min(x, ch);
			std::cout << x << "\n";
		}
	}
	return 0;
}
```





## 要点

注意两个必须。先去掉第一个必须，快速找到答案，再加回来缩减答案。



# B. [ Z mod X = C](https://codeforces.com/problemset/problem/1684/B)

## 问题描述

输入a，b，c，输出x，y，z。满足：
$$
x \bmod y = a, \\
y \bmod z = b, \\
z \bmod x = c.
$$




## 问题思路

相当于：

x = oy + a，y=pz+b, z=qx+c。



令o=0，q=1, p=1：x=a，y=z+b, z=x+c => y>z  z >x x = a。



所以 x=a, z = a+c, y=a+c+b。



但是这存在问题：如果a=1，那么后续z%a必然等于0！



所以：令o=1, q=0, p=1，得到： z=c，y=c+b, x = c+b+a。



由于题目约束a < b < c，所以c绝对不为1！自然满足问题。



## 实现代码

```c++
#include<iostream>

int a, b, c, t;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b >> c ;
		std::cout << c + b + a << " " << c + b << " " << c << "\n";
	}
	return 0;
}
```



## 要点

把mod转为a=kb+r。然后带入0或者1来求解，这里有个坑，所以绝不能让x=a=1！

