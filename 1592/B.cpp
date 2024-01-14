#include<iostream>
#include<algorithm>

int t, n, x, a[100001], b[100001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> x;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			b[i] = a[i]; 
		}
		if(2 * x <= n || n == 1) {
			std::cout << "YES\n";
			continue;
		}
		
		std::sort(b+1, b+1+n);
		
		bool ok = true;
		for(int i = n-x+1; i <= x; i++) {
			if(b[i] != a[i]) {
				ok = false;
				break;
			}
		}
		
		if(ok) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		} 
		
	}
	return 0;
} 
