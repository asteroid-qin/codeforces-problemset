# A. [Mahmoud and a Triangle](https://codeforces.com/problemset/problem/766/B)

## 问题描述

给定长度n的字符串a和长度m的字符串b，求a与b最长非公共子序列的长度。



## 问题思路

显然，这个长度在[0, max(n ,m)]



那么在什么情况下能取到max(n, m)呢？显然是选择a与b之间最长的那个，同时我们发现：如果a不等于b，那么总能取到max(n, m)。



总结：

a=b，输出-1，否则输出max(n, m)



## 实现代码

```c++
#include<iostream>

std::string a, b;
int main() {
	std::cin >> a >> b;
	int n = a.size(), m = b.size();
	if(a == b) std::cout << "-1\n";
	else std::cout << std::max(n, m) << "\n";
	return 0;
} 
```



## 要点

贪心



# B. [Mahmoud and a Triangle](https://codeforces.com/problemset/problem/766/B)

## 问题描述

给定长度n的整数数组a，判断a中是否存在三个元素，满足：

1. x + y > z
2. x +  z > y
3. y + z > x



## 问题思路

排序，然后令a[i] =x , a[i-1] = y, a[i+1] = z，来判断是否条件即可。



判断条件很简单，但是为什么是 i-1和i+1呢？

给个简单的证明：



先固定i和i-1，尝试证明为什么i+1最优。

i和i-1 i+1，满足要求，那么最好，可以输出结果。否则，一定找不到出来比i+1更优的数。因为a[i+1] <= a[j]，当j >= i+ 1时。所以：



如果a[i] + a[i-1] > a[i+1] 不满足，那么大于等于a[i]的a[j]自然也不满足

如果a[i] + a[i+1] > a[i-1] 不满足，显然升序排列后这是不可能的，舍去

如果a[i+1] + a[i-1] > a[i] 不满足，因为a[i+1] >= a[i]，所以加上a[i-1]后必然大于a[i]，所以这是不可能的，舍去。

因此，选择i+1最优。



同理可以证明选择i-1也是最优的。



总结：

循环a，索引i从1开始到n-2结束，如果a[i] + a[i-1] > a[i+1]，那么输出 YES，

否则一律输出NO



## 实现代码

```c++
#include<iostream>
#include<algorithm>

int n, a[100000];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::sort(a, a+n);
	
	for(int i = 1; i < n - 1; i++) {
		if(a[i] + a[i-1] > a[i+1]) {
			std::cout << "YES\n";
			return 0;
		}
	}
	
	std::cout << "NO\n";
	return 0;
}
```



## 要点

排序