#include<iostream>

std::string a, b;
int main() {
	std::cin >> a >> b;
	int n = a.size(), m = b.size();
	if(a == b) std::cout << "-1\n";
	else std::cout << std::max(n, m) << "\n";
	return 0;
} 
