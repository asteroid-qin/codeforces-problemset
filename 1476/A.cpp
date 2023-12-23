#include<iostream>

int t, n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		if(n % k ==0) {
			std::cout << "1\n";
			continue;
		}
		
		int ans;
		if(n < k) {
			ans = k / n; 
			if(k % n != 0) ans++;
		} else {
			ans = 2;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
} 
