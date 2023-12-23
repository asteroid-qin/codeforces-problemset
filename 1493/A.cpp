#include<iostream>

int t, a[1001], n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		int p = 0;
		for(int i = k + 1; i <= n; i++) {
			a[p++] = i;
		}
		
		for(int i = 1; i * 2 <= k; i++) {
			a[p++] = k - i;
		} 
		
		std::cout << p << "\n";
		for(int i = 0; i < p; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
