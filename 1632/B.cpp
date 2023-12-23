#include<iostream>
#include<cmath>

int t, n; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int p = 1;
		while(p * 2 <= n - 1) p *= 2;
		
		for(int i = p - 1 ; i >= 0; i--) {
			std::cout << i << " ";
		}
		
		for(int i = p; i < n; i++) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
