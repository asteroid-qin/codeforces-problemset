#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(k > (n - 1) / 2) {
			std::cout << "-1\n";
			continue;
		}
		
		std::cout << 1 << " ";
		for(int i = 2; i+1 <= n; i+=2) {
			if(k > 0) {
				std::cout << i+1 << " " << i << " ";
				k--;
			} else {
				std::cout << i << " " << i + 1 << " ";
			}
		}
		if(n % 2 == 0) {
			std::cout << n;
		}
		std::cout << "\n";
	}
	return 0;
}
