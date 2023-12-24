#include<iostream>

int t, n, cnt[26];
std::string s;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(char ch : s) cnt[ch-'a']++;
		
		for(int i = 0; i < 26; i++) {
			char ch = i + 'a';
			while(cnt[i] > 0) {
				std::cout << ch;
				cnt[i]--;
			}
		}
		std::cout << "\n";
	}
	return 0;
}
