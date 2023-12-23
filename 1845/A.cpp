#include<iostream>

int t, n, k, x;

void slv() {
	std::cin >> n >> k >> x;
	
	if(x != 1) {
		std::cout << "YES\n" << n << "\n";
		for(int i = 0; i < n; i++) {
			std::cout << "1 ";
		}
		std::cout << "\n";
		return;
	}
	
	if(k == 1) {
		std::cout << "NO\n";
		return;
	}
	
	if(k == 2) {
		if(n & 1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n" << n / 2 << "\n";
			for(int i = 0; i < n / 2; i++) {
				std::cout << "2 ";
			}
			std::cout << "\n";
		}
		
		return;
	}
	
	std::cout << "YES\n" << n / 2 << "\n";
	if(n & 1) {
		for(int i = 1; i < n / 2; i++) {
			std::cout << "2 ";
		}
		std::cout << "3\n";
	} else {
		for(int i = 0; i < n / 2; i++) {
			std::cout << "2 ";
		}
		std::cout << "\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
