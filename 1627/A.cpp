#include<iostream>

int t, n, m, r, c;
char a[51][51];

int slv() {
	std::cin >> n >> m >> r >> c;
	bool f = true;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		std::cin >> a[i][j];
		if(a[i][j]=='B') f = false;
	 } 
	 
	if(f) {
		return -1;
	}
	r--; c--;
	if(a[r][c] == 'B') {
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i][c] == 'B') {
			return 1;
		}
	}
	
	for(int i = 0; i < m; i++) {
		if(a[r][i] == 'B') {
			return 1;
		}
	}
	return 2;
} 
int main() {
	std::cin >> t;
	while(t--) {
		std::cout << slv() << "\n";
	}
	return 0;
}
