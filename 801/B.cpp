#include<iostream>

std::string x, y;
int main() {
	std::cin >> x >> y;
	int n = x.size();
	for(int i = 0; i < n; i++) {
		if(x[i] < y[i]) {
			std::cout << "-1\n";
			return 0;
		}
	}
	std::cout << y << "\n";
	return 0;
} 
