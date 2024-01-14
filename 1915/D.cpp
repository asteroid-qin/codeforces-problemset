#include<iostream>
#include<vector>
int t, n;
std::string s;

bool isV(char ch) {
	return ch == 'a' || ch == 'e';
}

bool check(int i) {
	return !isV(s[i]) && isV(s[i+1]) && !isV(s[i+2]);
}

void slv() {
	std::cin >> n >> s;
	
	std::vector<std::string> ans;
	for(int i = n-1; i -1 >= 0; i--) {
		if(i-2>=0 && check(i-2)) {
			ans.push_back(s.substr(i-2, 3));
			i -= 2;
		} else {
			ans.push_back(s.substr(i-1, 2));
			i -= 1;
		}
	}
	
	n = ans.size();
	for(int i = n-1; i >= 0; i--) {
		std::cout << ans[i];
		if(i != 0) std::cout << ".";
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
