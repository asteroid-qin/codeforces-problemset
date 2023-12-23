#include<iostream>
#include<algorithm>

int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		
		int k = 0;
		int i = 0;
		while(i < n) {
			int j = i+1;
			while(j < n && a[j] == a[i]) j++;
			
			// [i, j-1]内a[i]相等
			k = std::max(k, j-i);
			
			// 跳转
			i = j; 
		} 
		
		int ans = 0;
		while(k < n) {
			// 移动 cnt 次 
			int cnt = std::min(k, n - k);
			
			// k加上移动
			k += cnt;
			
			// ans需要移动+复制 
			ans += cnt + 1; 
		}
		std::cout << ans << "\n";
	}
	return 0;
}
