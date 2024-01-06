#include<iostream>

int n;
int main() {
	std::cin >> n;
	int k = n / 7, r = n % 7;
	
	int a = k * 2 + std::min(2, r);
	int b = k * 2 + std::max(0, r - 5);
	
	std::cout << b << " " << a << "\n";
	return 0;
} 
