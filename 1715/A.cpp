#include<iostream>


int main() {
	int t, n, m;
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		if(n == 1 && m == 1) {
			std::cout << "0\n";
			continue;
		}
		
		if(m > n) std::swap(n, m);
		
		std::cout << n + m + m - 2 << "\n";
	}
	return 0;
}
