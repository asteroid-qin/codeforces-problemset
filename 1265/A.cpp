#include<iostream>

int t;
std::string s, a;
bool has[3];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		int n = s.size();
		a.resize(n);
		
		// 1.		
		for(int i = 0; i < n; i++) {
			if(s[i] == '?') a[i] = 'a';
			else a[i] = s[i];
		}
		
		// 2.
		for(int i = 0; i < n; i++) {
			if(s[i] != '?') continue;
			
			for(int j = 0; j < 3; j++) has[j] = 0;
			
			if(i - 1 >= 0) {
				has[a[i-1]-'a']=1;
			}
			if(i + 1 < n) {
				has[a[i+1]-'a']=1;
			}
			
			for(int j = 0; j < 3; j++) {
				if(!has[j]) {
					a[i] = j + 'a';
					break;
				}
			}
		}
		
		// 3. 
		bool check = true;
		for(int i = 1; i < n; i++) {
			if(a[i] == a[i-1]) {
				check = false;
				break;
			}
		}

		if(!check) {
			std::cout << "-1\n";
			continue;
		}	
		std::cout << a << "\n";
	}
	return 0;
} 
