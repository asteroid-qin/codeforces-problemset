#include<iostream>
#include<algorithm>

int t, n, a[100], b[100];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin  >> n;
		for(int i = 0; i < n; i++) std::cin>> a[i];
		for(int i = 0; i < n; i++) std::cin>> b[i];
		
		std::sort(a, a+n);
		std::sort(b, b+n);
		
		for(int i = 0; i < n; i++) std::cout << a[i] << " ";
		std::cout << "\n";
		for(int i = 0; i < n; i++) std::cout << b[i] << " ";
		std::cout << "\n";
	}
	return 0;
} 
