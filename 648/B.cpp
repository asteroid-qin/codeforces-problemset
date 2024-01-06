#include<iostream>

int n, a[2000];
bool vis[2000];
int main() {
	std::cin >> n;
	n *= 2;
	
	int sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	
	int k = sum * 2 / n;
	
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		
		for(int j = 0; j < n; j++) {
			if(vis[j] || a[i] + a[j] != k) continue;
			
			vis[j] = true;
			
			std::cout << a[i] << " " << a[j] << "\n";
			break;
		}
	}
	return 0;
}
