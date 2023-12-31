#include<iostream>
#include<algorithm>

int n, a[2000];
int main() {
	std::cin >> n;
	n *= 2;
	bool f = true;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		
		if(i != 0 && a[i] != a[i-1]) {
			f = false;
		}
	}
	
	if(f) {
		std::cout << "-1\n";
		return 0;	
	}
	std::sort(a, a+n);
	
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	return 0;
} 
