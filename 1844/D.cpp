#include<iostream>
int t, n;

void slv() {
	std::cin >> n;
	
	int x = 2;
	while(n % x == 0) x++;
	
	for(int i = 0; i < n; i++) {
		char ch = 'a' + (i % x);
		std::cout << ch;
	}
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
