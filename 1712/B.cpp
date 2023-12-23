#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int p = 0;
		if(n & 1) {
			std::cout << 1 << " ";
			n--;
			p = 1;
		}
		
		for(int i = 1; i <= n; i += 2) {
			int x = 2 * ( (i / 2) + 1) + p;
			std::cout << x << " " <<  x - 1 << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
