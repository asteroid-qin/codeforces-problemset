#include<iostream>

int t, n, a[400002], p;

void slv() {
	std::cin >> n;
	p = 0;
	
	for(int i = 0, x, pre; i < n; i++) {
		std::cin >> x;
		if(i == 0 || pre <= x) {
			a[p++] = x;
		} else {
			a[p++] = x; a[p++] = x;
		}
		pre = x;
	}
	
	std::cout << p << "\n";
	for(int i = 0; i < p; i++) {
		std::cout << a[i] << " ";
	}	
	
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
