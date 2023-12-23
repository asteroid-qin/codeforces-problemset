#include<iostream>
#include<vector>

int t, n;
std::vector<std::string> ans[51];

void init() {
	ans[1].push_back("()");
	
	for(int i = 2; i <= 50; i++) {
		ans[i].resize(i);
		
		for(int j = 0; j < i-1; j++) {
			ans[i][j] = "()" + ans[i-1][j];
		}
		
		for(int j = 0; j < i; j++) {
			ans[i][i-1] += "(";
		}
		for(int j = 0; j < i; j++) {
			ans[i][i-1] += ")";
		}
	}	
}

void slv() {
	std::cin >> n;
	for(auto& v: ans[n]) {
		for(auto& s : v) {
			std::cout << s;
		}
		std::cout << "\n";
	}
}
int main() {
	init(); 
	std::cin >> t;
	while(t--) slv();
	return 0;
}
