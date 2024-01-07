#include<iostream>

int n, n1, n2;
bool has[101];
int main() {
	std::cin >> n >> n1 >> n2; 
	
	int x;
	for(int i = 0; i < n1; i++) {
		std::cin >> x;
		has[x] = true;
	}
	
	for(int i = 1; i <= n; i++) {
		if(has[i]) std::cout << "1 ";
		else std::cout << "2 ";
	}
	
	std::cout << "\n";
	return 0;
} 
