#include<iostream>
#include<cmath>

int n, a[100];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int x = 1;
	for(int i = 0; i < n; i++) {
		int p = a[i] & (a[i] - 1);
		x = std::max(x, a[i] - p);
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % x == 0) cnt++;
	}
	
	std::cout << x << " " << cnt << "\n";
	return 0;
}
