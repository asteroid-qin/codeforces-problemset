#include<iostream>
#include<algorithm>

int n, a[100000];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::sort(a, a+n);
	
	int l = 0, r = n - 1;
	while(l < n && a[l] == a[0]) l++;
	while(r >=0 && a[r] == a[n-1]) r--;
	
	std::cout << std::max(0, r - l + 1) << "\n";
	return 0;
}
