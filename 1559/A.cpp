#include<iostream>

int n, t;
int main () {
	std::cin >> t;
	while(t--) {
		int x;
		std::cin >> n >> x;
		for(int i = 1; i < n; i++) {
			int y;
			std::cin >> y;
			
			x &= y;
		}
		
		std::cout << x << "\n";
	}
	return 0;
} 
