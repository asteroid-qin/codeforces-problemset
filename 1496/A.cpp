#include<iostream>

int t, n, k;
std::string s;

bool check() {
	std::cin >> n >> k >> s;
	
	if(2*k+1 > n) {
		return false;
	}
	for(int i = 0; i < k; i++) {
		if(s[i] != s[n-i-1]) return false;
	}
	return true;
}
int main() {
	std::cin >> t;
	while(t--) {
		if(check()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
	return 0;
}
