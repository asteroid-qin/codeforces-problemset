#include<iostream>

int t;
int n, a[100000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		int x = 0;
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			
			if(a[i] & 1) x++;
			int b = x / 3, r = x % 3;
			
			if(i == 0) {
				std::cout << a[i] << " ";
				continue;
			}
					
			if(r == 1) std::cout << sum - b - 1 << " ";
			else std::cout << sum - b << " ";
		}
		
		std::cout << "\n";
	}
	return 0;
} 
