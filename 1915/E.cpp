#include<iostream>
#include<set>
#define ll long long
int t, n, a[200001];

bool slv() {
	std::cin >> n;
	
	ll odd = 0, even = 0, x;
	std::set<ll> have;
	have.insert(0);
	
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(i&1) odd += a[i];
		else even += a[i];
		
		if(have.count(odd - even)) return true;
		
		have.insert(odd -even);
	}
	
	return false;
}
int main(){
	std::cin >> t;
	while(t--) {
		if(slv()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
		
	return 0;
} 
