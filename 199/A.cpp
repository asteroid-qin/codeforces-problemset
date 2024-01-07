#include<iostream>

int n, x, a[100];
int main() {
	n = 2;
	a[0] = 0, a[1] = 1;
	
	for(int i = 2; i <= 100; i++) {
		a[i] = a[i-1] + a[i-2];
		if(a[i] > 1e9) break;
		n++;
	}
	std::cin >> x;
	
	if(x == 0) {
		std::cout << "0 0 0\n";
		return 0;
	}
	
	if(x == 1) {
		std::cout << "0 0 1\n";
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] == x) {
			std::cout << 0 << " " << a[i-2] << " " << a[i-1] << "\n";
			return 0;
		}
	}
	std::cout << "-1\n";
	return 0;
}
