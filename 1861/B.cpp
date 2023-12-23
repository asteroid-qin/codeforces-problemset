#include<iostream>

int main() {
	int t, n;
	std::string a, b, ans;
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		n = a.size();
		
		ans = "NO\n";
		for(int i = 0; i < n - 1; i++) {
			if(a[i] == b[i] && a[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1') {
				ans = "YES\n";
				break;
			}
		}
		
		std::cout << ans;
	}
	return 0;
} 
