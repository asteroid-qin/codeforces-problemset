#include<iostream>
#include<algorithm>

int t, n, a[100001], b[100001];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	if(n&1) {
		std::cout << "NO\n";
		return; 
	}
	
	std::sort(a,a+n);
	
	int m = n / 2;
	
	for(int i = 0; i < n; i += 2) {
		b[i] = a[n - i - 1];
		b[i+1] = a[n - i - 1- m];
	}
	for(int i = 0; i < m; i++) {
		b[i*2] = a[n - i - 1];  
		b[i*2 + 1] = a[n - i - 1 - m];
	}
	
	for(int i = 0; i < n; i += 2) {
		int x = b[(i-1+n)%n];
		int y = b[(i+1)%n];
		if(x >= b[i] || y >= b[i]) {
			std::cout << "NO\n";
			return; 
		}
	}	
	
	for(int i = 1; i < n; i += 2) {
		int x = b[(i-1+n)%n];
		int y = b[(i+1)%n];
		if(x <= b[i] || y <= b[i]) {
			std::cout << "NO\n";
			return; 
		}
	}
	
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << " ";
	}
}

int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
} 
