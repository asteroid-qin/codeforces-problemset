#include<iostream>

int t;
int main() {
	std::cin >> t;
	long long a, b, c;
	while(t--) {
		std::cin >> a >> b >> c;
		std::cout << (a + b + c) / 2 << "\n";
	}
	return 0;
} 
