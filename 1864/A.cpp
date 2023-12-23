#include<iostream>

int t, x, y, n, a[1001];

void slv() {
	std::cin >> x >> y >> n;
	a[n-1] = y;
	int p = 1;
	for(int i = n-2; i >= 0; i--) {
		a[i] = a[i+1] - p;
		p++;
	}
	
	if(a[0] < x) {
		std::cout << "-1\n";
		return;
	}
	
	a[0] = x;
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
