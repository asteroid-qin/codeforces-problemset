#include<iostream>

int t, n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(i == 1 && j == 1) std::cout << "W";
				else std::cout << "B";
			}
			std::cout << "\n";
		}
	}
	return 0;
} 
