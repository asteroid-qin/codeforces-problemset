#include<iostream>
#include<vector>

int t, idx[128];

void slv() {
	std::string s, t;
	std::cin >> s >> t;
	
	std::vector<int> cnt(26, 0); 
	for(char ch : s) cnt[ch-'a']++;
	
	for(int i = 0; i < cnt[0]; i++) {
		std::cout << 'a';
	}	
	
	if( "abc" != t || !cnt['a'-'a'] || !cnt['b'-'a'] || !cnt['c'-'a'] ) {
		for(int i = 0; i < cnt[1]; i++) {
			std::cout << 'b';
		}
		for(int i = 0; i < cnt[2]; i++) {
			std::cout << 'c';
		}
	} else {
		for(int i = 0; i < cnt[2]; i++) {
			std::cout << 'c';
		}
		for(int i = 0; i < cnt[1]; i++) {
			std::cout << 'b';
		}
	}
		
	for(int i = 3; i < 26; i++) {
		while(cnt[i]--) std::cout << char('a'+i);
	}
	std::cout << "\n";
} 

int main(){
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
