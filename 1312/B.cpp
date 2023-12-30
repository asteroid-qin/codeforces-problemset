#include<iostream>

int t, n, a[101];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= 100; i++) a[i] = 0;
		for(int i = 0; i < n; i++) {
			int x; std::cin >> x;
			a[x]++;
		}		
		
		for(int i = 100; i >= 1; i--) {
			while(a[i]--) std::cout << i << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
