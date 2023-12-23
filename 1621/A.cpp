#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(k > (n + 1) / 2) {
			std::cout << "-1\n";
			continue;
		}
		
        int p = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == p*2-1 && j == p*2-1 && p <= k) {
					std::cout << "R";
                    p++;
				} else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}
	return 0;
} 
