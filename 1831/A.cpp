#include<iostream>

int t, n, a[101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		int x = 1 + n;
		
		for(int i = 1; i <= n; i++) {
			std::cout << x - a[i] << " ";
		}		
		
	}
}
