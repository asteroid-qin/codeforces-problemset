#include<iostream>

int n;
int main() {
	std::cin >> n;
	
	std::cout << n <<  "\n";
	for(int i = 0; i < n; i++) std::cout << "1 ";
	std::cout << "\n";
	return 0;
}
