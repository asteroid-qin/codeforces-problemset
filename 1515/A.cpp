#include<iostream>
#include<algorithm>

int t, n, a[100], x;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> x;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		
		if(sum < x) {
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << a[i] << " ";
			}
			std::cout << "\n";
			continue;
		}
		
		if(sum == x) {
			std::cout << "NO\n"; 
			continue;
		}
		
		std::sort(a, a+n);
		
		sum = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			if(sum == x && i + 1 < n) {
				sum += a[i+1] - a[i];
				std::swap(a[i], a[i+1]);
			}
		}
		
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
