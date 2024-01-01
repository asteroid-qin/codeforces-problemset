#include<iostream>

std::string s;
int main() {
	std::cin >> s;
	int n = s.size();
	
	std::cout << s;

	for(int i = n-1; i >= 0; i--) std::cout << s[i];
	std::cout << "\n";
	
	return 0;
} 
