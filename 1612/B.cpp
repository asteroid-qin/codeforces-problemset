#include<iostream>

bool sel[101];
int ans[101];

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, a, b;
		std::cin >> n >> a  >>  b;

		int k = n / 2;
		for(int i = 1; i <= n; i++) {
			sel[i] = 0;
		}
		
		int p = 0;
		ans[++p] = a;
		sel[a] = sel[b] = 1;
				
		for(int i = n; i >= 1 && p <= k; i--) {
			if(sel[i]) continue;
			sel[i] = 1;
			ans[++p] = i;
		}
		
		ans[++p] = b;
		for(int i = 1; i <= n; i++) {
			if(sel[i]) continue;
			ans[++p] = i;
		}
		
		int mi = 1e9, mx = 0;
		for(int i = 1; i <= k; i++) {
			mi = std::min(mi, ans[i]);
			mx = std::max(mx, ans[i+k]);
		}
		
		if(mi != a || mx != b) {
			std::cout << "-1\n";
			continue;
		} 
		
		for(int i = 1; i <= n; i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
