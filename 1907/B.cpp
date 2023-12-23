#include<iostream>
#include<vector>

int t;
std::string s;
int main() {
	std::cin >> t;

	while(t--) {
		std::cin >> s;
		std::vector<int> a, b;
		int sz = s.size();

		for(int i = 0; i < sz; i++) {
			char ch = s[i]; 
			if(ch == 'B') {
				if(!a.empty()) a.pop_back();
			} else if(ch == 'b') {
				if(!b.empty()) b.pop_back();
			} else {
				
				if(ch > 'Z') b.push_back(i);
				else a.push_back(i);
			}	
		}
		
		int i = 0, j = 0, n = a.size(), m = b.size();
		while(i < n && j < m) {
			if(a[i] < b[j]) {
				std::cout << s[a[i]];
				i++;
			} else {
				std::cout << s[b[j]];
				j++;
			}
		}
		while(i < n) {
			std::cout << s[a[i]];
			i++;
		}
		
		while(j < m) {
			std::cout << s[b[j]];
			j++;
		} 
		std::cout << "\n";
	}
	return 0;
}
