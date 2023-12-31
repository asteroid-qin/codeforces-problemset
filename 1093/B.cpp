#include<iostream>
#include<algorithm>

int t;
int main() {
	std::cin >> t;
	while(t--) {
		std::string s;
		std::cin >> s;
		int n = s.size();
		
		std::sort(s.begin(), s.end());
		if(s[0] == s[n-1]) {
			std::cout << "-1\n";
		} else {
			std::cout << s << "\n";
		}
	}
	return 0;
}
