#include<iostream>
#include<set>

int t, n;

bool check() {
	std::cin >> n;
	std::set<int> st;
	
	int x;
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		st.insert(x);
	}		
	return st.size() != n;
} 
int main() {
	std::cin >> t;
	while(t--) {
		if(check()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}
