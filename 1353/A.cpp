#include<iostream>

int t, n, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		int ans;
		if(n == 1) {
			ans = 0;
		} else if(n == 2) {
			ans = m;
		} else {
			ans = m * 2;
		}
		std::cout << ans << "\n";
	}
	return 0;
}
