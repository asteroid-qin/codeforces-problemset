#include<iostream>

int t, n, k, r, c, a[501];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k >> r >> c;
		
		for(int p = r, q = c; p >= 1; p--, q++) {
			a[p] = q;
		}
		
		for(int p = r, q = c; p <= n; p++, q--) {
			a[p] = q;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if((j - a[i]) % k == 0) std::cout << "X";
				else std::cout << ".";
			}
			std::cout << "\n";
		}
	}
	return 0;
}
