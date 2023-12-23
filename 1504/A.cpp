#include<iostream>

bool judge(std::string& s) {
	int l = 0, r = s.size() - 1;
	while(l < r) {
		if(s[l] != s[r]) return false;
		l++; r--;
	}
	return true;
} 

std::string s;
int t;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		s += "a";
		if(!judge(s)) {
			std::cout << "YES\n" << s<< "\n";
			continue;
		}
		
		s.pop_back();
		s = "a" + s;
		if(!judge(s)) {
			std::cout << "YES\n" << s<< "\n";
			continue;
		}
		
		std::cout << "NO\n";
	} 
	return 0;
}
