#include<iostream>

int n, a[4], d;
int main() {
	n = 4;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	std::cin >> d;
	
	int ans = 0;
	
	for(int i = 1; i <= d; i++) {
		for(int j = 0; j < n; j++) {
			if(i % a[j] == 0) {
				ans++;
				break;
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}
