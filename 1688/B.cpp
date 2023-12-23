#include<iostream>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int odd = 0;
		
		int ctx = 31;
		for(int i =0; i < n; i++) {
			int x; std::cin >> x;
			if(x&1) odd++;
			
			int cur = 0;
			while(x > 0) {
				if(x & 1) break;
				x >>= 1;
				cur++;
			}
			ctx = std::min(ctx, cur);
		}
		if(odd > 0) {
			std::cout << n - odd << "\n";
			continue;
		}
		// 全部都是偶数
		std::cout << n -1 + ctx << "\n";
	}
	return 0; 
} 
