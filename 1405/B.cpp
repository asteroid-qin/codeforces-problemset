#include<iostream>

int t, n;
int main(){
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		long long cur = 0, sum = 0;
		for(int i = 0; i < n; i++) {
			int x; std::cin >> x;
			sum += x;
			cur = std::max(cur, sum * -1);
		}
		std::cout << cur << "\n";
	}
	return 0;
} 
