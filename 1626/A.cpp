#include<iostream>

int t;
std::string s;
int cnt[26];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> s;
		for(int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}

		for(char ch : s) {
			cnt[ch-'a']++;
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 2) {
				std::cout << (char)(i+'a');
			}
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 2) {
				std::cout << (char)(i+'a');
			}
		}
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 1) {
				std::cout << (char)(i+'a');
			}
		}
		std::cout << "\n";
	}
	return 0;
}
