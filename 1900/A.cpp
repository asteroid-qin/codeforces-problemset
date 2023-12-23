#include<iostream>

int t, n;
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		
		int cnt = 0;
		bool f = false;
		for(int i = 0; i < n; i++) {
			if(i - 1 >= 0 && i + 1 < n && s[i] == s[i-1] && s[i] == s[i+1] && s[i] == '.') {
				f = true;
				break;
			}
			
			if(s[i] == '.') {
				cnt++;
			}
		}
		
		if(f) {
			cnt = 2;
		} 
		
		std::cout << cnt << "\n";
	}
	return 0;
} 
