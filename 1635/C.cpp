#include<iostream>
#include<vector>

struct Node{
	int x, y, z;
};

int t, n, a[200000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int idx = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(a[i] >= 0) {
				idx = i;
			}
		}
		
		bool ok = true;
		for(int i = idx; i < n; i++) {
			if(i - 1 >= 0 && a[i - 1] > a[i]) {
				ok = false;
				break;
			}
		}
		
		if(!ok) {
			std::cout << "-1\n";
			continue;
		}
		
		std::vector<Node> vec;
		for(int i = 0; i < idx - 1; i++) {
			vec.push_back({i+1, idx, idx+1});
		}
		
		std::cout << vec.size() << "\n";
		
		for(auto& nd : vec) {
			std::cout << nd.x << " " << nd.y << " " << nd.z << "\n";
		}
	}
	return 0;
} 
