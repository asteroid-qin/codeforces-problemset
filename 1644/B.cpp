#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cout << i;
			for(int j = n; j >= 1; j--) {
				if(j == i) continue;
				std::cout << " " << j;
			}
			std::cout << "\n";
		}
		
	}
	return 0;
}
