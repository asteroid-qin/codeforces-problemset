#include<iostream>
#include<cmath>

int t, m;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> m;
		std::string s = std::to_string(m);
		int sz = s.size();
		int k = pow(10, sz-1);
		
		std::cout << m - k << "\n";
	}
	
	return 0;
}
