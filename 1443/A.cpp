#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 4 * n; i >= 2 * n + 2; i -= 2) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
