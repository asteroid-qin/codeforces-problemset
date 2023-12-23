#include<iostream>

int t, fa[51];
std::string s;

int find(int x) {
	return fa[x] = x == fa[x] ? x : find(fa[x]);
}

void merge(int a, int b) {
	fa[find(a)] = find(b);
}
void slv() {
	std::cin >> s;
	int n = s.size();
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	// ºÏ²¢ 
	for(int i = 1; i < n; i++) {
		if(s[i-1] == 'E') {
			merge(i, i+1);
		}
	}
	// Áé»ê 
	if(s[n-1] == 'E') merge(1, n);
	 
	for(int i = 0; i < n; i++) {
	 	if(s[i] == 'E') continue;
	 	int a = i + 1, b = ( (i + 1) % n) + 1;
	 	if(find(a) == find(b)) {
	 		std::cout << "NO\n";
	 		return;
		}
	}
	 std::cout << "YES\n";	
}
int main () {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
} 
