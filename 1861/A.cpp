#include<iostream>

std::string s;
int main() {
	int t; std::cin >> t;
	while(t--) {
		std::cin >> s;
		for(char ch : s) {
			if(ch == '1' || ch == '3') std::cout << ch;
		}
		std::cout << "\n";
	}
	return 0;
} 
