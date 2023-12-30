#include<iostream>

int t, n, a, b;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> a >> b;
		
		for(int i = 0; i < n; i++) {
			std::cout << (char)(i % b + 'a');
		}
		std::cout << "\n";
	}
	return 0;
} 
