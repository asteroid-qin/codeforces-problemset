#include<iostream>

int t, n, a[2][1000], k1, k2, w, b;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k1 >> k2 >> w >> b;

		int max_w = k1 / 2 + k2 / 2;
		if( (k1 & 1) && (k2 & 1) ) max_w++;
		
		k1 = n - k1, k2 = n - k2;
		int max_b = k1 / 2 + k2 / 2;
		if( (k1 & 1) && (k2 & 1) ) max_b++;
		
		if(w <= max_w && b <= max_b)  {
			std::cout << "YES\n";
		}  else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
