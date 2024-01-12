#include<iostream>

int t, n, a[200001]; 

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		
		int ans = (1 << 30 ) - 1;
		for(int i = 0; i < n; i++) {
			if(i == a[i]) continue;
			ans &= i;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}
