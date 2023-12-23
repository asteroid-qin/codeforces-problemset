#include<iostream>

int a[200000], n, k, t;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		int cnt = 0;
		
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			
		}

		for(int i = 0; i < n; i++) {
			if(i - 1 >= 0 && i + 1 < n && a[i-1] + a[i+1] < a[i] )	{
				cnt++;
			}
		}
		
		if(k == 1) cnt = std::max(cnt , (n - 1) / 2);
		
		std::cout << cnt << "\n";
	}
	
	return 0;
}
