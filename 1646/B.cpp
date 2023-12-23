#include<iostream>
#include<algorithm>

int t, n, a[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		long long sumb = 0, suma = 0;
		
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		
		std::sort(a+1, a+1+n);
		
		// 倒着k个
		int k = (n-1) / 2;
		for(int i = n; i >= n+1-k; i--) {
			suma += a[i];
		}
		
		k++;
		// 顺着k+1个
		for(int i = 1; i <= k; i++) {
			sumb += a[i];
		} 
		
		if(suma > sumb) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}
