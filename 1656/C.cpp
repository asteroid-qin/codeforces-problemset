#include<iostream>
#include<algorithm> 

int t, n, a[100001];

int main () {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		std::sort(a, a+n);
		bool has0 = false, hasEq = false;	
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) has0 = true;
			
			if(i + 1 < n && a[i] + 1 == a[i+1] ) hasEq = true;
		}
		
		if(has0 && hasEq) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}
