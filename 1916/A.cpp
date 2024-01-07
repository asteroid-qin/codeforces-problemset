#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		
		long long d = 1, x;
		for(int i = 0; i < n; i++) {
			std::cin >> x;
			d *= x;
		}
		
		if(2023 % d == 0) {
			std::cout << "YES\n";
			
			for(int i = 1; i < k; i++) std::cout << "1 ";
			
			std::cout << 2023 / d << "\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
