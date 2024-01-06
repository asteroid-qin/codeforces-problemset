#include<iostream>

int n, m;
char a[100][100];
int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	
	int pre = 0;
	for(int j = 0; j < n; j++) {
		if(a[j][0] == '*') pre++;
	}
	
	int x = 0, y = 0;
	for(int i = 1; i < m; i++) {
		int cur = 0;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == '*') cur++;
		}
		
		x = std::max(x, cur - pre);
		y = std::max(y, pre - cur);
		pre = cur;
	}
	
	std::cout << x << " " << y << "\n";
	
	return 0;
}
