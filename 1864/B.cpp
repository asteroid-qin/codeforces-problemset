#include<iostream>
#include<algorithm>

int t;
int n, k;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		
		std::string s, a, b;
		
		std::cin >> s;
		
		if(k & 1) {
			for(int i = 0; i < n; i++) {
				if(i&1) a += s[i];
				else b += s[i];
			}
			
			std::sort(a.begin(), a.end());
			std::sort(b.begin(), b.end());
			
			int p = 0, q = 0;
			for(int i = 0; i < n; i++) {
				if(i&1) s[i] = a[p++];
				else s[i] = b[q++];
			}
		} else {
			std::sort(s.begin(), s.end());
		}
		
		std::cout << s << "\n";
	}
	return 0;
}
