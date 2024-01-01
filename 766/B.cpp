#include<iostream>
#include<algorithm>

int n, a[100000];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::sort(a, a+n);
	
	for(int i = 1; i < n - 1; i++) {
		if(a[i] + a[i-1] > a[i+1]) {
			std::cout << "YES\n";
			return 0;
		}
	}
	
	std::cout << "NO\n";
	return 0;
}
