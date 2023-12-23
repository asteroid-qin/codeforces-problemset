#include<iostream>


int n, t;
void slv() {
	std::cin >> n;
	if(n == 1) {
		std::cout<< "1\n";
		return ;
	}
	
	if(n & 1) {
		std::cout << "-1\n";
		return ;
	}
	for(int i = 1; i <= n / 2; i++) {
		// n-4 n-5 n-2 n-3 n n-1
		// 2 1 4 3 6 5
		std::cout << i * 2 << " " << i * 2 - 1 << " ";
	}
	std::cout << "\n";
}

int main(){
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
