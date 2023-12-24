#include<iostream>

int t, n;
std::string s;

bool check() {
	std::cin >> s;
	n = s.size();
	return (n % 2 == 0) && s[0] != ')' && s.back() != '(';
}
int main() {
	std::cin >> t;
	while(t--) {
		if(check()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
