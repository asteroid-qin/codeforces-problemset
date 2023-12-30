#include<iostream>

int t, n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		if(n == 1) {
			std::cout << "-1\n";
			continue;
		}
		
		if(n % 3 == 1) {
			for(int i = 2; i < n; i++)
				std::cout << "2";
			std::cout << "33\n";
		} else {
			for(int i = 1; i < n; i++)
				std::cout << "2";
			std::cout << "3\n";
		}
	}
	return 0;
} 
