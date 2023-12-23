#include<iostream>

std::string s, t;
int T, n, m;

int main() {
	std::cin >> T;
	while(T--) {
		std::cin >> n >> m;
		std::cin >> s >> t;
		
		
		
		bool f = true;
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) {
				f = false;
				break;
			}
		}
		if(f) {
			std::cout << "YES\n";
			continue; 
		}
		
		
		f = true;
		for(int i = 1; i < m; i++) {
			if(t[i] == t[i-1]) {
				f = false;
				break;
			}
		} 
		if(!f) {
			std::cout << "NO\n";
			continue;
		}
		
		
		char st = t[0], ed = t.back();
		f = true;
		
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) {
				if(s[i] != ed && s[i-1] != st) {
					continue;
				}
				
				f = false;
				break;
			}
		}
		
		if(f) std::cout << "YES\n";
		else std::cout << "NO\n";
	}	
	
	return 0;
}
