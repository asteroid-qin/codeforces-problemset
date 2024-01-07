#include<iostream>

int t, n, k;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		for(int i = 1; i <= k; i++) {
			std::cout << i << " ";
		}
		for(int i = n; i >= k+1; i--) {
			std::cout << i << " ";
		}
		
		std::cout << "\n";
	}
	
	return 0;
} 
