#include<iostream>

int t, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		char ch;
		std::string s;
		
		for(int i = 1; i <= 2*n-1; i++) {
			std::cin >> ch;
			if(i&1) s += ch;
		} 
		
		std::cout << s << "\n";
	}
	return 0;
} 
