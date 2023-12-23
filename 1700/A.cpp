#include<iostream>

int t, n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		long long ans = (1 + m) * m / 2;
		
		for(int i = 2; i <= n; i++) {
			ans += (i - 1) * m + m;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}
