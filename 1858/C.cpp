#include<iostream>

int t, n, a[100001];
bool vis[100001];
int main() {
	
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		
		int p = 1;
		for(int i = 2; i <= n; i++) {
			int j = i;
			
			while(j <= n && !vis[j]) {
				vis[j] = 1;
				
				a[p++] = j;
				
				j <<= 1;
			}
		}
		for(int i = 1; i < n; i++) {
			std::cout << a[i] << " ";
		}
		std::cout << "1\n";
	} 
	return 0;
} 
