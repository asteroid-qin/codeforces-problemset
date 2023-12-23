#include<iostream>


int t, n, a[101];

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::cout << n << "\n";
		for(int i = 1; i <= n; i++) {
			a[i] = i;
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
		
		for(int k = 1; k < n; k++) {
			std::swap(a[k], a[k+1]);
			
			for(int i = 1; i <= n; i++) {
				std::cout << a[i] << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
}
