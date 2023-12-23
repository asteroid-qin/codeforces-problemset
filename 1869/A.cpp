#include<iostream>

int t, n, a;

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++)
	 std::cin >> a;
	
	
	if(n&1) {
		// 如果是奇数，会多出一个 
		std::cout << "4\n";
		std::cout << "1 " << n << "\n"; 
		std::cout << "2 " << n << "\n";
		std::cout << "1 2\n";
		std::cout << "1 2\n";
		return; 
	}
	
	std::cout << "2\n";
	
	std::cout << "1 " << n << "\n"; 
	std::cout << "1 " << n << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
