#include<iostream>

int t, n, pl[200001], pr[200001];

bool check(int k) {
	int cur_l = 0, cur_r = 0;
	
	for(int i = 0; i < n; i++) {
		cur_l -= k;
		cur_r += k;	
		
		cur_l = std::max(cur_l, pl[i]);
		cur_r = std::min(cur_r, pr[i]);
		
		if(cur_l > cur_r) {
			return false;
		}
	}
	return true;
}

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> pl[i] >> pr[i];
		}
		
		int l = 0, r = 1e9, mid;
		
		while(l < r) {
			mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		
		std::cout << l << "\n";
	}
	
	return 0;
}
