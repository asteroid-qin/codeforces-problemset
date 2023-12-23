#include<iostream>

int t, n, a[2000], b[2000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int p = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(a[i] & 1) b[p++] = a[i];
		}
		
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 == 0) {
				b[p++] = a[i];
			}
		}
		
		for(int i = 0; i < n; i++) {
			std::cout << b[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
