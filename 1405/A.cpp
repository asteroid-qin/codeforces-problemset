#include<iostream>

int t, n, a[101];
int main(){
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		for(int i = 0; i < n; i++) std::cout << a[n-1-i] << " ";
		std::cout << "\n";
	}
	return 0;
} 
