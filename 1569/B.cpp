#include<iostream>

int t, n;
char mp[51][51];
std::string s;

void slv() {
	std::cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		bool has = true;
		for(int j = i; j <= n; j++) {
			if(i == j) mp[i][j] = 'X';
			else {
				if(s[i-1] == '1') {
					mp[i][j] = '=';
					mp[j][i] = '=';
				} else if(has) {
					has = false;
					mp[i][j] = '+';
					mp[j][i] = '-';		
				} else {
					mp[i][j] = '=';
					mp[j][i] = '=';		
				}
			}
		}
	}
	
	// 判断是否符合要求
	for(int i = 1; i <= n; i++) {
		int win = 0, lose = 0;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] == '+') win++;
			if(mp[i][j] == '-') lose++;
		}
		
		if(s[i-1] == '1' && lose != 0 ) {
			std::cout << "NO\n";
			return;
		} 
		
		if(s[i-1] == '0' && win == 0) {
			std::cout << "NO\n";
			return;
		}
	} 
	
	// YES
	std::cout <<"YES\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << mp[i][j];
		}
		std::cout << "\n";
	} 
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
