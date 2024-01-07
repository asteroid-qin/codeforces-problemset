#include<iostream>

int n1, n2, k1, k2;
int main() {
	std::cin >> n1 >> n2 >> k1 >> k2;
	if(n2 >= n1) {
		std::cout << "Second\n";	
	} else {
		std::cout << "First\n";	
	}
	
	return 0;
} 
