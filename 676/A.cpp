#include<iostream>

int n, a[101];
int main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		a[x] = i;
	}
	
	int p = std::min(a[1], a[n]);
	int q = std::max(a[1], a[n]);
	
	std::cout << std::max(n - p, q - 1) << "\n";
	return 0;
}
