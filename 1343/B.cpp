#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		if(n%4 != 0) {
			std::cout << "NO\n";
			continue;
		} 
		std::cout << "YES\n";
		for(int i = 2; i <= n; i+=2) std::cout << i << " ";
		
		for(int i = 1; i <= n; i+=2) {
			if(i != n-1) std::cout << i << " ";
			else std::cout << i + n / 2 << " ";
		}
		
		std::cout << "\n";
	}
	return 0;
}
