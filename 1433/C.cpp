#include<iostream>

int n, t, a[300000];

int work() {
	std::cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin>> a[i];
		mx = std::max(mx, a[i]);
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] != mx) continue;
		
		if((i - 1 >= 0 && a[i-1] != mx) || (i + 1 < n && a[i + 1] != mx) ) {
			return i+1;
		}
	}
	return -1;
}
int main() {
	std::cin >> t;
	while(t--) {
		std::cout << work() << "\n";
	}
	return 0;
} 
