#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		if(n & 1) {
			std::cout << "3 1 2 ";
			for(int i = 4; i <= n; i+=2) {
				std::cout << i+1 << " " << i << " ";
			}
		} else {
			for(int i = 1; i <= n; i+=2) {
				std::cout << i+1 << " " << i << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}
