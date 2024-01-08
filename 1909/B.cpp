#include<iostream>
#include<set>
#define ll long long
int t, n;

ll a[101];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		for(ll x = 2; x <= 1e18;) {
			std::set<ll> st;
			
			for(int i = 0; i < n; i++) {
				st.insert(a[i] % x);
			}
			
			if(st.size() == 2) {
				std::cout << x << "\n";
				break;
			} else {
				x *= 2;
			}
		}
	}
	return 0;
} 
