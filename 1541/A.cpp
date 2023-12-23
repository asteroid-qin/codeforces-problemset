#include<iostream>

int n, t;

void slv() {
	std::cin >> n;
	if(n&1) {
		std::cout << "3 1 2 ";
		for(int i = 4; i <= n; i += 2) {
			std::cout << i + 1 << " " << i << " ";
		}
		std::cout << "\n";
		return;
	}
	
	for(int i = 1, p = 1; i <= n; i += 2, p++) {
		std::cout << p * 2 << " " << p * 2 - 1 << " ";
	}
	std::cout << "\n";
}

int main () {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
