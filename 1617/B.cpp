#include<iostream>

int t, n;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

void slv() {
	std::cin >> n;
	if(n % 2 == 0) {
		std::cout <<  n / 2 << " " << (n / 2 - 1) << " " << 1 << "\n";
		return; 
	}
	
	for(int i = 2; i <= n; i++) {
		if(gcd(i, n-i-1) == 1) {
			std::cout << i << " " << n - i - 1 << " " << 1 << "\n";
			return;
		}
	}
}

int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
