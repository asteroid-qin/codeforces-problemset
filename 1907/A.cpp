#include<iostream>

int t;
int main() {
	std::cin >> t;
	while(t--) {
		std::string s;
		std::cin >> s;
		
		for(char i = 'a'; i <= 'h'; i++) {
			if(i == s[0]) continue;
			std::cout << i << s[1] << "\n";
		}		
		
		for(int i = 1; i <= 8; i++) {
			if(i == s[1]-'0') continue;
			
			std::cout << s[0] << i << "\n";
		}
	}
	return 0;
}
