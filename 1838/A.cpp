#include<iostream>


int t, n, a[101];
void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	int mx = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < 0) {
			std::cout << a[i] << "\n";
			return;
		}
		mx = std::max(mx, a[i]);
	}
	
	std::cout << mx << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
