#include<iostream>
#include<set>

int t, n, m, a, b, c;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		std::set<int> has;
		
		while(m--) {
			std::cin >> a >> b >> c;
			has.insert(b);			
		}
		
		int mid = 1;
		for(int i = 1; i <= n; i++) {
			if(!has.count(i) ) {
				mid = i;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			if(i == mid) continue;
			std::cout << i << " " << mid << "\n";
		}
	}
	return 0;
} 
