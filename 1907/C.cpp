#include<iostream>
#include<set>

int t, n, cnt[26];
std::string s;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		int mx = 0;		
		for(int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}
		for(char ch : s) {
			cnt[ch-'a']++;
		}
		
		for(int i = 0; i < 26; i++) {
			mx = std::max(mx, cnt[i]);
		} 

		if(mx >= n - mx) {
			std::cout << mx - (n - mx) << "\n";
			continue;
		}
		
		int ans = n&1;
		std::cout << ans << "\n"; 
	}
	return 0;
}
