#include<iostream>

int t, n, l, r;

void slv() {
	std::cin >> n >> l >> r;
	for(int i = 1; i <= n; i++) {
		int p = (l + i - 1) / i * i;
		if(p > r) {
			std::cout << "NO\n";
			return ;
		}
	}
	
	std::cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		int p = (l + i - 1) / i * i;
		std::cout << p << " ";
	}
	std::cout << "\n";
} 
int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
}
