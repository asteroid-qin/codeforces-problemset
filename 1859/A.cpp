#include<iostream>

int t, n, a[100];
void slv() {
	std::cin >> n;
	
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == mx) {
			cnt++;
		}
	}
	
	if(cnt == n) {
		std::cout << "-1\n";
		return;
	} 
	
	std::cout << n - cnt << " " << cnt << "\n";
	for(int i = 0; i < n; i++) {
		if(a[i] != mx) std::cout << a[i] << " ";
	}
	std::cout << "\n";
	for(int i = 0; i < cnt; i++) {
		std::cout << mx << " ";
	}
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
