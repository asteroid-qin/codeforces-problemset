#include<iostream>

int k, r;
int main() {
	std::cin >> k >> r;
	for(int i = 1; i <= 10; i++) {
		int x = i * k % 10;
		if(x == r || x == 0) {
			std::cout << i << "\n";
			return 0;
		}
	}
	return 0;
} 
