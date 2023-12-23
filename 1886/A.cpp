#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int b, c;
		if(n % 3 == 0) b = 4, c = n - 5;
		else b = 2, c = n - 3;
		
		if(b < c) {
			std::cout << "YES\n";			
			std::cout << 1 << " " << b << " " << c << "\n";
			continue;
		}
		
		std::cout << "NO\n";
				
	}
	return 0;
}
