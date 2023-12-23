#include<iostream>

int t, n, k, H, m;

void slv() {
	std::cin >> n >> m >> k >> H;
	
	int ans = 0, x;
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		x = abs(H - x);
		if(x % k == 0 && k <= x && x <= (m-1) * k) {
//			std::cout << x << "#\n";
			ans++;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
