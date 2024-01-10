#include<iostream>
#include<cmath>

int t, n, a[100001];

void slv(int r) {
	if(r < 0) return;
	int s = sqrt(r*2); s = s * s;
	int l = s - r;
	slv(l-1);
	for(; l <= r; l++, r--) {
		a[l] = r;
		a[r] = l;
	}
} 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		slv(n-1);
		for(int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
