# A. [Equal or Not Equal](https://codeforces.com/problemset/problem/1620/A)

## 问题描述

给定环形字符串（$$a_{n+1}=a_1$$）的消息：$$a_i = a_{i+1} ? $$，判断是否合法。



## 问题思路

如果这不是环形的，自然一定可以找到合法的。



环形在此基础上加了个头尾的限制条件：



可以把所有E连接起来。在循环所有的N，如果N执向的2个元素是在一个集合则矛盾，否则不做处理。



可以用并查集完成这个过程，维护所有元素是相等的集合。

## 实现代码

```c++
#include<iostream>

int t, fa[51];
std::string s;

int find(int x) {
	return fa[x] = x == fa[x] ? x : find(fa[x]);
}

void merge(int a, int b) {
	fa[find(a)] = find(b);
}
void slv() {
	std::cin >> s;
	int n = s.size();
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	// 合并 
	for(int i = 1; i < n; i++) {
		if(s[i-1] == 'E') {
			merge(i, i+1);
		}
	}
	// 灵魂 
	if(s[n-1] == 'E') merge(1, n);
	 
	for(int i = 0; i < n; i++) {
	 	if(s[i] == 'E') continue;
	 	int a = i + 1, b = ( (i + 1) % n) + 1;
	 	if(find(a) == find(b)) {
	 		std::cout << "NO\n";
	 		return;
		}
	}
	 std::cout << "YES\n";	
}
int main () {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
} 
```





## 要点

另一种思路是：如果全部相等那自然是YES；有一个N，那么绝对不合法，NO；有一个以上N，因为相等集合被分隔了，YES。