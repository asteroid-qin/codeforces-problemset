#include<iostream>

int n, x, a[101];
int main() {
	std::cin >> n  >> x;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	
	int ans = a[x] == 1;
	
	for(int i = 1; i <= n; i++) {
		int p = x - i, q = x + i;
		if(p >= 1 && q <= n) {
			if(a[p] + a[q] == 2) ans += 2;
		} else if(p >= 1) {
			ans += a[p] == 1;
		} else if(q <= n) {
			ans += a[q] == 1;
		}
	}
	
	std::cout << ans << "\n";
	
	return 0;
} 
