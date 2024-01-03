#include<iostream>

std::string s; 
int main() {
	std::cin >> s;
	std::cout << s;
	for(int i = s.size() - 1; i >= 0; i--) std::cout << s[i];
	std::cout << "\n";
	return 0;
}
