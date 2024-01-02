#include<iostream>

int n, a[200001];
int main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for(int i = 1; i * 2 <= n + 1; i++) {
		if(i&1) std::swap(a[i], a[n-i+1]);
	}
	
	for(int i = 1; i <= n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
