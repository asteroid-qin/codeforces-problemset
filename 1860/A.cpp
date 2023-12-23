#include<iostream>
#include<vector>
#include<stack>

int t;
std::string s;

void slv() {
	std::cin >> s;
	int n = s.size();
	
	std::string a, b;
	for (int i = 0; i < 2 * n; ++i) {
	  a += "()"[i & 1];
	  b += ")("[i < n];
	}
	if (a.find(s) == std::string::npos) {
	  std::cout << "YES\n" << a << '\n';
	} else if (b.find(s) == std::string::npos) {
	  std::cout << "YES\n" << b << '\n';
	} else {
	  std::cout << "NO\n";
	} 
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
