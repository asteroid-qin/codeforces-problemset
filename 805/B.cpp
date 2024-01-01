#include<iostream>

std::string s = "bba"; 
int n;
int main() {
	std::cin >> n;
	s.resize(n);
	
	if(n <= 3) std::cout << s << "\n";
	else {
		for(int i = 3; i < n; i++) {
			if(s[i-2] == 'a') s[i] = 'b';
			else s[i] = 'a';
		}
		std::cout << s << "\n";
	}
		
	return 0;
}
