#include<iostream>

int a[2][50];
int t, n, m;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int k = 0, x = 0; k < m; k += 2) {
			a[0][k] = x; a[0][k+1] = 1 - x;
			a[1][k+1] = x; a[1][k] = 1 - x;
			x = 1 - x; 
		}
		
		for(int i = 0; i < m; i++) {
			std::cout << a[0][i] << " ";
		}
		std::cout << "\n";
		
		for(int i = 0; i < m; i++) {
			std::cout << a[1][i] << " ";
		}
		std::cout << "\n";
		
		
		for(int k = 2, x = 1; k < n; k += 2) {
			for(int j = 0; j < m; j++) {
				std::cout << a[x][j] << " ";
			}
			std::cout << "\n";
			
			for(int j = 0; j < m; j++) {
				std::cout << a[1-x][j] << " ";
			}
			std::cout << "\n";
			x = 1 - x; 
		}
		
	}
	return 0;
}
