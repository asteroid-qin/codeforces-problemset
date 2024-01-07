#include<iostream>

int n;
int main() {
	std::cin >> n;
	if(n > 2) {
		for(int i = n; i >= 1; i--) {
			std::cout << i << " ";
		}
	} else {
		std::cout << "-1";
	}
	
	std::cout << "\n";
	return 0;
}
