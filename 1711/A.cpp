#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		std::cout << n;
		for(int i = 2; i <= n; i++) {
			std::cout << " " << i - 1;
		}
		std::cout << "\n";
	}
	return 0;
} 
