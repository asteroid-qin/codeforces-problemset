#include<iostream>

int t, n, a[3];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int x;
		for(int i = 0; i < 3; i++) a[i] = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> x;
			a[x%3]++;
		}
		int k = n / 3, ans = 0;
		for(int i = 0; i < 3; i++) {
			int carry = a[i] - k;
			if(carry > 0) {
				ans += carry;
				a[i] -= carry;
				a[(i+1)%3] += carry;
			}
		}	
		for(int i = 0; i < 3; i++) {
			int carry = a[i] - k;
			if(carry > 0) {
				ans += carry;
				a[i] -= carry;
				a[(i+1)%3] += carry;
			}
		}
		std::cout << ans << "\n";	
	}
	
	return 0;
} 
