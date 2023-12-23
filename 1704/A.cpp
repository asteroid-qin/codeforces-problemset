#include<iostream>

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::string a, b;
		std::cin >> n >> m >> a >> b;
		
		
		bool fa = true, fb = false;
		for(int i = m - 1; i > 0; i--) {
			if(a[n-1-m+1+i] != b[i]) {
				fa = false;
				break;
			}
		}
		
		// ≥¢ ‘»√
		for(int i = 0; i < n - m + 1; i++) {
			// [p, n-1]   n-p+1=m   
			if(a[i] == b[0]) {
				fb = true;
				break;
			}
		} 
		
		if(fa && fb) std::cout << "YES\n";	
		else  std::cout << "NO\n";	
	}
	return 0;
}
