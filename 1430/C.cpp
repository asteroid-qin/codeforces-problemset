#include<iostream>

int n, t;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		std::cout << "2\n";
		if(n == 2) {
			std::cout << "1 2\n";
			continue;
		} 
		
		std::cout << n << " " << n - 2 << "\n";
		std::cout << n - 1 << " " << n - 1 << "\n";
		for(int i = n - 3; i >= 1; i--) {
			std::cout << i << " " << i + 2 << "\n";
 		}
	}
	return 0;
} 
