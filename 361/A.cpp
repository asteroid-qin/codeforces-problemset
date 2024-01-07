#include<iostream>

int n, k;
int main() {
	std::cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) std::cout << k << " ";
			else std::cout << "0 ";
		}
		
		std::cout << "\n";
	}
	return 0;
} 
