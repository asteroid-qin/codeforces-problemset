#include<iostream>

int n, t;
std::string s; 

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		if(s == std::string(n, '1')) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
	
	return 0;
} 
