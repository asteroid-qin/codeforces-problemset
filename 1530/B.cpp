#include<iostream>
#include<cmath>

int t, n, m;
char mp[21][21];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				mp[i][j] = '0';
			}
		}		
		
		
		// ио 
		for(int i = 1; i <= m-2; i+=2) {
			mp[1][i] = '1';
		}	
		// об 
		for(int i = 1; i <= m-2; i+=2) {
			mp[n][i] = '1';
		}
		
		// вС
		for(int i = 1; i <= n-2; i+=2) {
			mp[i][1] = '1';
		}	
		// ср 
		for(int i = 1; i <= n-2; i+=2) {
			mp[i][m] = '1';
		}
		mp[n][m] = '1';
		
		// out
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				std::cout << mp[i][j];
			}
			std::cout << "\n";
		}
		 
	}
	return 0;
} 
