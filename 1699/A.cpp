#include<iostream>


int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n&1) std::cout << "-1\n";
		else std::cout << 0 << " " << n / 2 << " " << "0\n";
	}
	return 0;
}
