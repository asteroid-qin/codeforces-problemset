#include<iostream>

int n, t;
std::string s;
int main() {
	std::cin >> n >> t >> s;
	
	while(t--) {
		for(int i = 0; i < n - 1; i ++) {
			if(s[i] == 'B' && s[i+1] == 'G') {
				std::swap(s[i], s[i+1]);
				i++;
			}
		}
	}	
	std::cout << s << "\n";

	return 0;
}
