#include<iostream>

int main() {
	std::string s;
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		
		int n = s.size();
		int i = 0;
		int ans = 0;
		bool noOne = true;
		
		for(; i < n; ) {
			while(i < n && s[i] != '0') {
				i++;
				noOne = false; 
			}
			
			if(i < n) {
				ans++;
			}
			while(i < n && s[i] == '0') i++;
		}
		
		if(ans == 0) std::cout << "0\n";
		else if(ans == 1 || noOne) std::cout << "1\n";
		else std::cout << "2\n";
	}
	return 0;
} 
