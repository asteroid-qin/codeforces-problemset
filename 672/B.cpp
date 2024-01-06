#include<iostream>

std::string s;
int a[26], n;
int main() {
	std::cin >> n >> s;
	
	if(n > 26) {
		std::cout << "-1\n";
		return 0;
	}
	
	for(char ch : s) a[ch-'a']++;
	
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		if(a[i] > 1) ans += a[i] - 1;
	}
	std::cout << ans << "\n";
	
	return 0;
} 
