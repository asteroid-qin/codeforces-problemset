#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int st = 1;
		if(n % 2 == 0) {
			st = 2;
			std::cout << n / 2 + 1 << " "; 
		}
		for(int i = st; i <= n; i++) std::cout << i << " ";
		
		
		std::cout << "\n";
	}
} 
