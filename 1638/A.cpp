#include<iostream>

int t, n, idx[501], a[501];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		int dif = -1;
		
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			idx[a[i]] = i;
			if(dif == -1 && a[i] != i) {
				dif = i;
			}
		}
		
		int l, r;
		if(dif == -1) {
			l = 1;
			r = 1;
		}  else {
			l = dif;
			r = idx[dif];
		}
		
		while(l < r) std::swap(a[l++], a[r--]);
		
		for(int i = 1; i <= n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
} 
