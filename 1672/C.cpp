#include<iostream>

int t, n, a[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		int st = 0;
		while(st + 1 < n && a[st] != a[st + 1] ) st++;
		
		int ed = n-1;
		while(ed - 1 >= 0 && a[ed] != a[ed - 1] ) ed--;
		
		int len = ed - st + 1;
		if(len < 3) {
			std::cout << "0\n";
		} else {
			std::cout << std::max(1, len - 3) << "\n";
		}		
	}
	return 0;
} 
