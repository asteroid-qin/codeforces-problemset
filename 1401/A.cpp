#include<iostream>

int t, n, k;
int main(){
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;

		if(n < k) {
			std::cout << k - n << std::endl;
		} else if(n % 2 == k % 2) {
			std::cout << 0 << std::endl;
		} else {
            std::cout << 1 << std::endl;
		}
	}
	return 0;
} 
