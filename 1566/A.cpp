#include<iostream>

int t, n, s, k;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		k = n / 2;
		std::cout << s / (k + 1) << "\n";
	}
	return 0;
} 
