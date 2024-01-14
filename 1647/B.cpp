#include<iostream>

int t, n, m;
char a[100][100];

int check(int x, int y) {
	int cnt = a[x][y] == '1';
	cnt += a[x+1][y+1] == '1';
	cnt += a[x][y+1] == '1';
	cnt += a[x+1][y] == '1';
	return cnt;
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cin >> a[i][j];
			}
		}
		
		bool ok = true;
		for(int i = 0; i < n-1 && ok; i++) {
			for(int j = 0; j < m-1; j++) {
				if(check(i, j) == 3) {
					ok = false;
					break;
				}
			}
		}
		
		if(ok) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
