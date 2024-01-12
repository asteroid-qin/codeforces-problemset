#include<iostream>

int t, n;
std::string s;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		long long ans = 1;
		for(int i = 1;  i < n; i++) {
			if(s[i] == s[i-1]) ans++;
			else ans += i + 1;
		}
		std::cout << ans << "\n";
	}
	return 0;
} 
