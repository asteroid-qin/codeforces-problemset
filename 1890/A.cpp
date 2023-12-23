#include<iostream>
#include<map>

int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		std::map<int, int> mp;
			
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			mp[x]++;
		}
		
		if(mp.size() == 1 || 
			( mp.size() == 2 && abs(mp.begin()->second - mp.rbegin()->second)  <= 1 ) ) {
			std::cout << "YES\n";
			continue;
		}
		
		std::cout << "NO\n";
	}
	return 0;
} 
