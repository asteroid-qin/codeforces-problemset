#include<iostream>

int a[26];

int main() {
	char ch;
	while((ch = getchar()) != '\n') {
		if('a' <= ch && ch <= 'z') {
			a[ch-'a']++;
		}
	}	
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		ans += a[i] > 0;
	}
	std::cout << ans << "\n";
	return 0;
}
