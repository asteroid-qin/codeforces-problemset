#include<iostream>

int t, n, a[101][101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				a[i][j] = 0;
			}
		}
		
		// Ð±Ïß		
		for(int i = 1; i <= n; i++) a[i][i] = 1;
		// ÏÂ 
		for(int i = 2, j = 1; i <= n; i++, j++) a[i][j] = 1;
		// ÉÏ 
		for(int i = 1, j = 2; j <= n; i++, j++) a[i][j] = 1;
		
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				std::cout << a[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
} 
