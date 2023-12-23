#include<iostream>

std::string s, a, b;
int t, n;

int slv() {
	int res = 0, m = s.size();
	
	for(int i = 0; i < m; i++) {
		if(s[i] == '0') res++;
	}
	bool hasZero = false, hasOne = false;
	
	for(int i = 0; i < m; i++) {
		if(s[i] == '0') hasZero = true;
		if(s[i] == '1') hasOne = true;
		
		if(hasZero && hasOne) {
			res++;
			hasZero = hasOne = false;
		}
	}
	return res;
}

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> a >> b;
		s = "";
		int ans = 0;
		
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				ans += 2 + slv();
				s = "";
			} else {
				s += a[i];
			}
 		}
 		
 		std::cout << ans + slv() << "\n";
	}
	return 0;
} 
