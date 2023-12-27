#include<iostream>

int n, t, a[3][100], p[100];

void slv() {
	std::cin >> n;
	for(int j = 0; j < 3; j++)
	for(int i = 0; i < n; i++) {
		std::cin >> a[j][i];
	}

	int pre = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			if(a[j][i] != pre) {
				p[i] = a[j][i];
				break;
			}
		}
		pre = p[i];
	}
	
	for(int j = 0; j < 3; j++) {
		if(a[j][n-1] != p[0] && a[j][n-1] != p[n-2] ) {
			p[n-1] = a[j][n-1];
			break;
		}
	}
	
	for(int i = 0; i < n; i++) {
		std::cout << p[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
