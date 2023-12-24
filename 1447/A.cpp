#include<iostream>

int t, n;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::cout << n << "\n";
		for(int i = 1; i <= n; i++) {
			std::cout << i << " ";
		} 
		
		std::cout << "\n";
	}
	return 0;
}
