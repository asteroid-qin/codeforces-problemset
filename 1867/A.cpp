#include<iostream>
#include<algorithm>

int t, n, a[40001], b[40001], ans[40001];
void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = i;
	}
	
	// 1 10 100
	// 1 2 3
	// 3 2 1
	
	std::sort(b+1, b+n+1, [&](const int x, const int y) {
		return a[x] > a[y];	
	});
	
	for(int i = 1; i <= n; i++) {
		ans[b[i]] = i;
		
	}	
	
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << " ";
	}
	
	std::cout << "\n";
}
// 1 5 1 10 5 100 50
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
