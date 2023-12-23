# C. [Set Construction](https://codeforces.com/problemset/problem/1761/C)

## 问题描述：

给你一个n*n的0-1矩阵b，要求构造n个set，满足：

1. 每个set的元素不重复
2. 每个set的值在1-n之间
3. 如果b[i] [j]=1，那么seti是setj的真子集，否则不是




## 问题思路：

思路：先**保证集合两两不同**，再根据连接关系设置真子集。

循环n个集合，为其设置从1开始的自增值，这样每个集合相互孤立。

此时，如果把一个集合的所有元素给另个集合，显然前一个集合必然是另个的真子集。

使用拓扑排序，自顶向上，根据条件给的连接关系，把一个集合的所有元素给另个集合，这样集合的传递性就简单解决了。



## 实现代码：

```c++
#include<iostream>
#include<set> 
#include<queue> 


int t, n;
char mp[100][100], ru[100];
std::set<int> ans[100];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		ru[i] = 0;
		ans[i].clear();
		ans[i].insert(i+1); // 灵魂一步
	}	
	
	char ch;
	for(int i =0; i < n; i++)
	for(int j =0; j < n; j++)
	{
		std::cin >> mp[i][j];
		if(mp[i][j]=='1') {
			ru[j]++;
		}
	}
	
	// 拓扑排序 
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		if(!ru[i]) {
			q.push(i);
		}
	}
	
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < n; i++) {
			if(mp[x][i] == '1') {
				// 设置为真子集
				for(int v : ans[x]) ans[i].insert(v);
				
				ru[i]--;
				if(!ru[i]) q.push(i);
			}
		}
	}
	
	
	// 输出答案 
	for(int i = 0; i < n; i++) {
		std::cout << ans[i].size();
		for(int x : ans[i]) {
			std::cout << " " << x; 
		}
		std::cout << "\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
```



## 要点：

