#include<iostream>

int n, c[6], d[6];
int main() {
	std::cin >> n;
	for(int i = 1; i <= 5; i++) c[i] = d[i] = 0;
	int x;
	
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		c[x]++;		
	}
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		d[x]++;
	}
	
	int ans = 0;
	for(int i = 1; i <= 5; i++) {
		int sum = c[i] + d[i];
		if(sum & 1) {
			std::cout << "-1\n";
			return 0;
		}
		ans += abs(sum / 2 - c[i]);
	}
	
	std::cout << ans / 2 << "\n";
	return 0;
} 
