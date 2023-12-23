#include<iostream>

int t, n;
void slv() {
	std::string s;
	std::cin >> s;
	n = s.size();
	
	char pre = '0';
	for(char& c : s) {
		if(c == '?') c = pre;
		else pre = c;
	}
	std::cout << s << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 

