#include<iostream>
#include<vector>

std::vector<int> vec[101];
int t, n, a[101], b[101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= 100; i++) {
			vec[i].clear();
		}
		
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			vec[a[i]].push_back(i);
			b[i] = 1;
		}
		
		
		int p = 1, cnt = 0;
		// 先找第一组
		for(; p <= 100; p++) {
			if(vec[p].size() < 2) {
				continue;
			}
			
			b[vec[p][0]] = 1;
			for(int i = 1; i < vec[p].size(); i++) {
				b[vec[p][i]] = 2;
			}
			cnt++; p++;
			break;
		}
		
		// 再找第二组 
		for(; p <= 100; p++) {
			if(vec[p].size() < 2) {
				continue;
			}
			
			b[vec[p][0]] = 1;
			for(int i = 1; i < vec[p].size(); i++) {
				b[vec[p][i]] = 3;
			}
			cnt++; p++;
			break;
		}
		
		if(cnt == 2) {
			for(int i = 0; i < n; i++) {
				std::cout << b[i] << " ";	
			}
			std::cout << "\n";
			continue;
		}
		 
		std::cout << "-1\n";
	}
	return 0;
}
