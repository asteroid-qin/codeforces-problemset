#include<iostream>

int a, b, c, t;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b >> c ;
		std::cout << c + b + a << " " << c + b << " " << c << "\n";
	}
	return 0;
}
