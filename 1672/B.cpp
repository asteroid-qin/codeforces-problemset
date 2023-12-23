#include<iostream>
#include<stack>

int t;
std::string s;

void slv() {
	std::cin >> s;
	int n = s.size();
	
	if(n < 2 || s.back() != 'B') {
		std::cout << "NO\n";
		return;
	}
	
	std::stack<int> st;
	for(int i = 0; i < n - 1; i++) {
		if(s[i] == 'A') {
			st.push(i);
			continue;
		}
		
		if(st.empty() || s[st.top()] == 'B') {
			std::cout << "NO\n";
			return;
		}
		st.pop();
	}
	
	if(st.empty()) {
		std::cout << "NO\n";
		return;
	}

	while(!st.empty()) {
		if(s[st.top()] != 'A') {
			std::cout << "NO\n";
			return;
		}
		st.pop();
	}
	
	std::cout << "YES\n";
} 
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
