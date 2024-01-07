#include<iostream>

int n, d, a[2000];
int main() {
	std::cin >> n >> d;
	for(int i = 0; i < n; i++)  std::cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] <= a[i-1]) {
			int cnt = (a[i-1] - a[i]) / d + 1;
			
			ans += cnt;
			a[i] += cnt * d;
		}
	}	

	std::cout << ans << "\n";
	return 0;
}
