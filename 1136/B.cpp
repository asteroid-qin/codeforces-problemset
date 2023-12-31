#include<iostream>

int n, k;
int main() {
	std::cin >> n >> k;
	std::cout << std::min(k-1, n-k) + 3 * n << "\n";
	return 0;
}
