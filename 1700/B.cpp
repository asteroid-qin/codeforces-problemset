#include<iostream>

int t, n, a[100002], b[100002];
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		for(int i = n; i >= 1; i--) {
			a[i] = s[n-i] - '0';
		}
		
		if(a[n] !=9) {
			for(int i = n; i >= 1; i--) {
				std::cout << 9 - a[i];
			}
			std::cout << "\n";
			continue;
		} 
		
		int carry = 0;
		for(int i = 1; i <= n; i++) {
			carry += a[i];
			b[i] = (11 - carry) % 10;
			carry = (a[i] + b[i] ) / 10;
		}
		
		for(int i = n; i >= 1; i--) {
			std::cout << b[i];
		}
		std::cout << "\n";
	}
	return 0;
}
