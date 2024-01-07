#include<iostream>

int t;
long long a, b;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
			
		if(a == 1) {
			std::cout << b * b << "\n";
			continue;
		}
		
		if(gcd(a, b) == a) {
			std::cout << b * b / a << "\n";
		} else {
			std::cout << a * b / gcd(a, b) << "\n";
		}
	}
	return 0;
}
