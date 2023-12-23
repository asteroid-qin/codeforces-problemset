#include<iostream>
#include<cmath>

int t, n;
int main(){ 
	int N = (int) (log(1e9) / log(3)) + 1;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(n > N) {
			std::cout << "NO\n";
			continue;
		}
		
		std::cout << "YES\n";
		int p = 1;
		for(int i = 1; i <= n; i++) {
			std::cout << p << " ";
			p *= 3;
		}
		std::cout << "\n"; 
	}
	return 0;
} 
