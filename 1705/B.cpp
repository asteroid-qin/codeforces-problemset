#include<iostream>

int t, n, a[200000];
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		for(int i = 0; i < n;i++) {
			std::cin >> a[i];
		}
		
		// 跳过所有0 
		int i = 0;
		while(i < n-1 && a[i] == 0) i++;
		
		// 否则计算其中0的个数并算答案 
		long long ans = 0;
		while(i < n-1) {
			if(a[i] == 0) ans++;
			else ans += a[i];
			
			i++;
		}
		
		std::cout << ans << "\n";
	}
	
	return 0;
}
