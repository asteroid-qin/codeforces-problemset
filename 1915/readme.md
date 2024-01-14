# A. [Odd One Out](https://codeforces.com/problemset/problem/1915/A)

## 问题描述

给你三个数字a 、b、c。

其中两个相等，但第三个与另外两个不同。找出恰好出现一次的值。



## 问题思路

模拟即可



## 实现代码

```c++
#include<iostream>

int t, n;
int main(){
	std::cin >> t;
	while(t--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if(a == b) std::cout << c << "\n";
		if(a == c) std::cout << b << "\n";
		if(b == c) std::cout << a << "\n";
	}
	return 0;
} 
```



## 要点

模拟



# B. [Not Quite Latin Square](https://codeforces.com/problemset/problem/1915/B)

## 问题描述

给定3行3列的矩阵a，a由'A'、'B'、'C'、'?'组成，现在需要替换'?'，使得：

1. a每行每列'A'、'B'、'C'恰好出现1次



注意：a中有且仅有1个'?'



## 问题思路

因为每行每列都恰好出现1次，所以和等于3。



可以对'A'、'B'、'C'计数，显然其中出现的次数不等于3，那么就是答案



## 实现代码

```c++
#include<iostream>

int t, n, a[3];

char slv() {
	for(int i = 0; i < 3; i++) a[i] = 0;
	
	for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++) 
	{
		char ch;
		std::cin >> ch;
		
		if(ch != '?') a[ch-'A']++;
	}
	
	for(int i = 0; i < 3; i++) {
		if(a[i] != 3) return i + 'A';
	}
	return 'A';
}
int main(){
	std::cin >> t;
	while(t--) {
		std::cout << (char)slv() << "\n";
	}
	return 0;
} 
```



## 要点

计数



# C. [Can I Square?](https://codeforces.com/problemset/problem/1915/C)

## 问题描述

给定n个桶里有a[i]个边长为1的正方形，判断它们能否凑成1个正方形



## 问题思路

因为边长为1，所以只要a[i]的和是个平方数，那么就可以构成1个正方形



## 实现代码

```c++
#include<iostream>
#include<cmath>
int t, n, a[3];

bool slv() {
	std::cin >> n;
	int x;
	long long sum = 0;
	
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		sum += x;
	}
	
	long long y = sqrt(sum);
	return sum == y * y;
}
int main(){
	std::cin >> t;
	while(t--) {
		if(slv()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
} 
```



## 要点

开方



# D. [Unnatural Language Processing](https://codeforces.com/problemset/problem/1915/D)

## 问题描述

给定长度n的字符串a，a仅由'a'、'b'、'c'、'd'、'e'构成。



定义'a'、'e'为元音，记为C；'b'、'c'、'd'为辅音，记为V。



现在需要将a划分为不重叠的CV或者CVC，中间用. 隔开



## 问题思路

如果是从头往后划分，如果是以CVC为开头，我们无法判断第2个C是需要和谁结合。因此我们需要倒着划分



尝试取后两个字符，如果等于 CV，那么显然就可以划分。否则必然是CVC，需要再弹出1个字符。



## 实现代码

```c++
#include<iostream>
#include<vector>
int t, n;
std::string s;

bool isV(char ch) {
	return ch == 'a' || ch == 'e';
}

bool check(int i) {
	return !isV(s[i]) && isV(s[i+1]) && !isV(s[i+2]);
}

void slv() {
	std::cin >> n >> s;
	
	std::vector<std::string> ans;
	for(int i = n-1; i -1 >= 0; i--) {
		if(i-2>=0 && check(i-2)) {
			ans.push_back(s.substr(i-2, 3));
			i -= 2;
		} else {
			ans.push_back(s.substr(i-1, 2));
			i -= 1;
		}
	}
	
	n = ans.size();
	for(int i = n-1; i >= 0; i--) {
		std::cout << ans[i];
		if(i != 0) std::cout << ".";
	}
	std::cout << "\n";
}
int main(){
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
} 
```



## 要点

倒着求



# E. [Romantic Glasses](https://codeforces.com/problemset/problem/1915/E)

## 问题描述

给定长度n的整数数组a，要求找到l和r，满足：

1. 1 <= l <= r <= n
2. a[l] + a[l+2] + a[l+4] + ... + a[r] = a[l+1] + a[l+3] + ... + a[r-1]，如果l和r是同奇偶性
3. a[l] + a[l+2] + a[l+4] + ... + a[r-1] = a[l+1] + a[l+3] + ... + a[r]，如果l和r非同奇偶性



## 问题思路

首先我们可以用前缀和快速求出任意区间内奇区间的和，和任意区间内偶区间的和

问题的难点在于，怎么样快速枚举子区间，直接枚举的复杂度是n * n，显然会超时



记a[r] 为 [1, r] 的奇区间的前缀和数组，b[r]为[1, r]的偶区间的前缀和数组。

显然，我们需要找到i和j，使得a[j]-a[i-1] = b[j]-b[i-1]



上面的等式可以变形为 a[i-1] - b[i-1] = b[j] - a[j]，也就是我们可以从1循环到n，判断 a[i] - b[i] 是否存在即可。

存在，那么代表存在1组满足题意

否则，把a[i]-b[i]加进去，继续循环判断



判断前i个数是否存在某个数，可以使用set



## 实现代码

```c++
#include<iostream>
#include<set>
#define ll long long
int t, n, a[200001];

bool slv() {
	std::cin >> n;
	
	ll odd = 0, even = 0, x;
	std::set<ll> have;
	have.insert(0);
	
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(i&1) odd += a[i];
		else even += a[i];
		
		if(have.count(odd - even)) return true;
		
		have.insert(odd -even);
	}
	
	return false;
}
int main(){
	std::cin >> t;
	while(t--) {
		if(slv()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
		
	return 0;
} 
```



## 要点

映射 公式变换



# F. [Greetings](https://codeforces.com/problemset/problem/1915/F)

## 问题描述

给定长度n的数组a和b，定义a[i]、b[i]为x坐标上的线段的两个端点，求所有线段重叠的次数



注意：a[i]、b[i]个个不同，且a[i] < b[i]



## 问题思路

显然，我们从a[i]到b[i]，如果某个点a[j]满足a[j] > a[i]且b[j] < b[i]，那么它们就会重叠一部分



因此我们可以对a[i]排序，使得 a[i] < a[i+1]。



此时，我们发现点i的贡献就是，[i+1, n]内b[j] < b[i]的数量，也就是求i后面小于b[i]的个数。答案自然是所有点的贡献的和。



如果把数据离散化，我们会发现这个问题的本质就是求逆序对。



求逆序对是个经典的题目，有种2做法：

1. 离散化后用树状数组算
2. 归并排序算



我这里采用归并排序



## 实现代码

```c++
#include<iostream>
#include<algorithm> 
#define ll long long
int t, n, arr[200001];
struct Node {
	int a, b;
	bool operator<(const Node& n) const{
		return a < n.a;
	}
} pr[200001];
ll ans;

void work(int l, int r) {
	if(l >= r) return;
	int mid = (l+r)/2;
	work(l, mid);
	work(mid+1, r);
	
	int i = l, j = mid + 1, p = l;
	while(i <= mid && j <= r) {
		if(pr[i].b <= pr[j].b) {
			arr[p] = pr[i].b;
			i++;
		} else {
			arr[p] = pr[j].b;
			ans += mid - i+1;
			j++;
		}
		p++;
	}
	
	while(i <= mid) {
		arr[p++] = pr[i++].b;
	}
	while(j <= r) {
		arr[p++] = pr[j++].b;
	}
	
	p = l;
	while(p <= r) {
		pr[p].b = arr[p];
		p++;
	}
}

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> pr[i].a >> pr[i].b;
	}
	std::sort(pr, pr + n);
	
	ans = 0;
	work(0, n-1);	
	std::cout << ans << "\n";
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 



```



## 要点

把没有见过的问题转化为见过的问题：求逆序对