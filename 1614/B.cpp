#include<iostream>
#include<algorithm>

int t, n, l, r, a[101], k;
void slv() {
	std::cin >> n >> l >> r >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a+n);

	int cnt = 0;
	for(int i = 0; i < n && a[i] <= k; i++) {
		if(l <= a[i] && a[i] <= r) {
			cnt++;
			k -= a[i];
		}
	}
	std::cout << cnt << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
