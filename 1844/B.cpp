#include<iostream>

int t, n;
void slv() {
	std::cin >> n;
	
	if(n > 2) {
		int x = 4, p = (n-1)/2+1;
		
		std::cout << "2 ";
		for(int i = 2; i < n; i++) {
			if(i != p) {
				std::cout << x << " ";
				x++; 
			} else {
				std::cout << "1 ";			
			}
		}
		std::cout << "3 ";
	} else {
		for(int i = 1; i <= n; i++) {
			std::cout << i << " ";	
		}
	}
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
