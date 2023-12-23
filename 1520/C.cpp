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
		
		// ��������
		for(int i = 1; i <= n; i++) {
			a[i][i] = i;
		} 
		
		int st = n + 1, ed = n * n, k = 2;
		while(k <= n) {
			// �����½�			
			int x = k, y = 1;
			while(x <= n) {
				a[x][y] = st;
				st++;
				x++;
				y++;
			}
			
			// �����½� 
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
