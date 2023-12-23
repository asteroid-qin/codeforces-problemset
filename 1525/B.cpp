#include<iostream>
#include<algorithm>
int t, n, a[51];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		bool fa = true;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			fa &= a[i] == i;
		}

		if(fa) {
			std::cout << "0\n";
			continue;
		}
		
		if(a[1] == 1 || a[n] == n) {
			std::cout << "1\n";
			continue;
		}
		if(a[1] == n && a[n] == 1) {
			std::cout << "3\n";
			continue;
		}
		std::cout << "2\n";
	}
	return 0;
} 
