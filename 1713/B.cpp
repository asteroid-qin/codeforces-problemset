#include<iostream>


int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int mx = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			mx = std::max(mx, a[i]);
		}
		std::string ans = "YES\n";
		
		for(int i = 0; i < n; i++) {
			if(mx == a[i]) {
				int j = i;
				while(j - 1 >= 0 && a[j] >= a[j - 1]) j--;
				
				if(j - 1 >= 0) {
					ans = "NO\n";
					break;
				}				

				j = i;
				while(j + 1 < n && a[j] >= a[j + 1]) j++;
				
				if(j + 1 < n) {
					ans = "NO\n";
				}
				break;
			}
		}
		
		std::cout << ans;
	}
	return 0;
}
