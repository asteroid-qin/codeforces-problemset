#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n == 1) {
			std::cout << "9\n";
			continue;
		}

		std::cout << "98";
		int st = 9;
		n -= 2;
		
		for(int i = 0; i < n; i++) {
			std::cout << st;
			st = (st + 1) % 10;
		}
		std::cout << "\n";
	}
	return 0;
}
