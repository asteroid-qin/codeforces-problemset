# A. [Circle Coloring](https://codeforces.com/problemset/problem/1408/A)

## 问题描述

这道题的原本的描述就非常清晰，小学生都看得懂。

给定长度n的三个数组：a，b，c。要求构造一个长度n的数组p，满足：

1. pi的值是ai、bi、ci中的一个。(ai、bi、ci 两两不相等）
2. p相邻的元素不相等。（注意，这里n与1相邻）



## 问题思路

因为a、b、c数组两两不相等，因此每次p都有3种选择。 

假如pi-1选择了x呢？显然pi一定能找到到一个和x不相同的数。（如果有一个数等于x，那么另外两个数一定不等于x，从这两个中随便选一个就行。如果都不等于，那么从这三个中随便选一个）



如此就可以从1选到n。到pn时，遇到了最大的挑战：

可不可以让pn既不等于pn-1也不等于p1? 答案是当然可以！上面证明了每次至少有2种选择（和pn-1不同的），所以如果其中一个等于p1那么换成另外一个，那么肯定就不等于了。



总结：

从1循环到n，每次从a b c中找到第一个不等于pre的值（每次更新pre=p[i]）。

对n再特殊处理一遍：从an bn cn 中找到一个不等于p[n-1]和p[1]的数。这个上面已经证明过了，一定可以找得到。



## 实现代码

```c++
#include<iostream>

int n, t, a[3][100], p[100];

void slv() {
	std::cin >> n;
	for(int j = 0; j < 3; j++)
	for(int i = 0; i < n; i++) {
		std::cin >> a[j][i];
	}

	int pre = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			if(a[j][i] != pre) {
				p[i] = a[j][i];
				break;
			}
		}
		pre = p[i];
	}
	
	for(int j = 0; j < 3; j++) {
		if(a[j][n-1] != p[0] && a[j][n-1] != p[n-2] ) {
			p[n-1] = a[j][n-1];
			break;
		}
	}
	
	for(int i = 0; i < n; i++) {
		std::cout << p[i] << " ";
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

模拟 证明