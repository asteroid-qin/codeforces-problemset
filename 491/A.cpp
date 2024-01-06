#include<iostream>

int n, a, b;

int main() {
	std::cin >> a >> b;
	int n = a + b + 1; 

	for(int i = 1; i <= a; i++) {
		std::cout << i << " ";
	}
	
	std::cout << n << " ";
	
	for(int i = n - 1; b > 0; i--, b--) {
		std::cout << i << " ";
	}
	
	std::cout << "\n";
}
