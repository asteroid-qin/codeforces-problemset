#include<iostream>

int main() {
	std::string s;
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		int n = s.size();
		if(n == 2) std::cout << s[1] << "\n";
		else {
			char x = '9';
			for(char ch : s) x = std::min(x, ch);
			std::cout << x << "\n";
		}
	}
	return 0;
}
