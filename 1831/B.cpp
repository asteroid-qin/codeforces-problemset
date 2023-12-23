#include<iostream>
#include<map>
#include<set>

int t, n, a[200001], b[200001];
void slv() {
	std::cin >> n;
	std::map<int,int> ca, cb;
	std::set<int> st;
	
	 
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		st.insert(a[i]);
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		st.insert(b[i]);
	}
	
	for(int i = 0; i < n; ) {
		int x = a[i], cnt = 1;
		i++;
		
		while(i < n && a[i] == x) {
			i++;
			cnt++;
		}
		
		ca[x] = std::max(ca[x], cnt);
	}
	
	for(int i = 0; i < n; ) {
		int x = b[i], cnt = 1;
		i++;
		
		while(i < n && b[i] == x) {
			i++;
			cnt++;
		}
		
		cb[x] = std::max(cb[x], cnt);
	}
	
	int ans = 0;	
	for(int v : st) {
		ans = std::max(ans, ca[v] + cb[v] );
	}
	std::cout << ans << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0; 
} 
