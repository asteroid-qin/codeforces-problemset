#include<iostream>
int t, a, b;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		if( (a + b) & 1) {
			std::cout << "-1 -1\n";
			continue;
		}
		if(a <= b) {
			std::cout << 0 << " " << (a+b)/2 << "\n";
		} else {
			std::cout << (a+b)/2 << " " << 0 << "\n";
		}
	}
	return 0;
}
