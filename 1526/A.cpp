#include<iostream>
#include<algorithm>

int t, n, a[60];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n*2; i++) {
			std::cin >> a[i]; 
		}
		std::sort(a+1, a+1+n*2);
		
		for(int i = 1; i <= n; i++) {
			std::cout << a[i] << " " << a[i+n] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
