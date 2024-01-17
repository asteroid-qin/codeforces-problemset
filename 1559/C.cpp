#include<iostream>

int t, n, a[10001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int idx = -1;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if(i != 1 && a[i] == 1 && a[i-1] == 0) {
				idx = i;
			}
		}
		
		if(!a[n]) {
			for(int i = 1; i <= n+1; i++) {
				std::cout << i << " ";
			}
			std::cout << "\n";
			continue;
		}
		
		if(a[1]) {
			std::cout << n + 1 << " ";
			for(int i = 1; i <= n; i++) {
				std::cout << i << " ";
			}
			
			std::cout << "\n";
			continue;
		}
		
		if(idx != -1) {
			for(int i = 1; i < idx; i++) {
				std::cout << i << " ";
			}
			
			std::cout << n + 1 << " ";
			
			for(int i = idx; i <= n; i++) {
				std::cout << i << " ";
			}
			
			std::cout << "\n";
			continue;
		}
		std::cout <<"-1\n";
	}
	return 0;
} 
