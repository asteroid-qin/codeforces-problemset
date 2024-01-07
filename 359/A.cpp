#include<iostream>

int n, m, a[51][51];

int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	
	bool has = false;
	for(int i = 0; i < n; i++) {
		has |= a[i][0] == 1 || a[i][m-1] == 1;
	}
	
	for(int i = 0; i < m; i++) {
		has |= a[0][i] == 1 || a[n-1][i] == 1;
	}
	
	if(has) std::cout << "2\n";
	else std::cout << "4\n";
	
	return 0;
}
