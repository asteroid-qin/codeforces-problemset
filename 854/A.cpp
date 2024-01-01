#include<iostream>

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	int n;
	std::cin >> n;
	for(int i = (n-1) / 2; i >= 1; i--) {
		int j = n - i;
		if( i < j && gcd(i, j) == 1) {
			std::cout << i << " " << j << "\n";
			return 0;
		}
	} 
	
	return 0;
}
