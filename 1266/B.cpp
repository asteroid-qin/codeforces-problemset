#include<iostream>

int t;

int main() {
	std::cin >> t;
	while(t--) {
		long long x, y;
		std::cin >> x;
		y = (x % 14) + 14;
		if(15 <= x && 15 <= y && y <= 20) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
} 
