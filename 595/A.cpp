#include<iostream>

int n, m, a[202];
int main() {
	std::cin >> n >> m;
	
	int ans = 0;
	while(n--) {
		for(int i = 1; i <= m*2; i++) {
			std::cin >> a[i];
		}
		
		for(int i = 1; i <= m; i++) {
			if(a[i*2-1] + a[i*2] > 0) ans++;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}

