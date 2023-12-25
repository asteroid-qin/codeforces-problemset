#include<iostream>

int t, n;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << "1 ";
		}
		std::cout << "\n";
	}
	return 0;
} 
