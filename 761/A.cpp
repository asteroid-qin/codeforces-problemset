#include<iostream>

int a, b;
int main() {
	std::cin >> a >> b;
	if(abs(a-b) <= 1 && a + b > 0) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
}
