#include<iostream>

int t, n, a[101][101]; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n == 1) {
			std::cout << "1\n";
			continue;
		}
		if(n == 2) {
			std::cout << "-1\n";
			continue;
		}
		
		// 设置中线
		for(int i = 1; i <= n; i++) {
			a[i][i] = i;
		} 
		
		int st = n + 1, ed = n * n, k = 2;
		while(k <= n) {
			// 先左下角			
			int x = k, y = 1;
			while(x <= n) {
				a[x][y] = st;
				st++;
				x++;
				y++;
			}
			
			// 再右下角 
			x = 1, y = k;
			while(y <= n) {
				a[x][y] = st;
				st++;
				x++;
				y++;
			}
			
			k++;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				std::cout << a[i][j]  << " ";
			}
			
			std::cout << "\n";
		}
	}
	return 0;
}
