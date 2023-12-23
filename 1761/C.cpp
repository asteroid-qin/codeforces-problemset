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
		ans[i].insert(i+1);
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
				// 为父集合加当前集合内容 
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
