#include<iostream>

int t, n, a[22];

bool check(int l, int r) {
	while(l + 1 <= r) {
		if(a[l] > a[l + 1]) {
			return false;
		}
		l++;
	}
	return true;
}

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		if(n <= 2) {
			std::cout << "YES\n";
			continue;
		}
		
		int p = 2;
		bool f = true;
		while((1 << p) <= n) {
			int ed = 1 << p;
			int st = ed / 2 + 1;
			if(!check(st, ed)) {
				f = false;
				break;
			}
			
			p++;
		}
		
		if(f && check((1 << (p-1) ) + 1, n)) {
			std::cout << "YES\n";
			continue;
		}
		
		std::cout << "NO\n";
	}
	return 0;
}
