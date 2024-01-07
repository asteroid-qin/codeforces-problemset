#include<iostream>

int n;
int main() {
	std::cin >> n;
	for(int i = 1; i <= 2*n +1; i++) {
		for(int j = 1; j <= 2*n+1; j++) {
			int x = n - abs(n+1-i) - abs(n+1-j);
			
			if(x >= 0) {
				std::cout << x;
			} else {
				std::cout << " ";
			}
			
			if(x == 0 && j > n) {
				break;
			} else {
				std::cout << " ";
			}
		}
		
		std::cout << "\n";
	}
	return 0;
}
