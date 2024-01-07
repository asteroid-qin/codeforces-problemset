#include<iostream>

int t, n, m;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		std::cout << std::max(n, m) << "\n";
	}
	
	return 0;
} 
