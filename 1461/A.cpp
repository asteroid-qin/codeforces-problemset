#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		for(int i = 0; i < n; i++) {
			char ch = 'a' + i % 3;
			std::cout << ch;
		}
		std::cout << "\n";
	}
	return 0;
}
