#include<iostream>

int t, k, n, a[1001][1001], b[1001][1001];
 
void slv() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) 
	for(int j = 1; j <= n; j++)
	std::cin >> a[i][j];
	
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[n - i + 1][n - j + 1] != a[i][j]) cnt++;
		}
	}
	cnt /= 2; // 这里因为算了2遍所以得/2
	 
	if(k < cnt || (n % 2 == 0  && (k - cnt) % 2 == 1) ) std::cout << "NO\n";
	else {
		std::cout << "YES\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
