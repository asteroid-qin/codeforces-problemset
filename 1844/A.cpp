#include<iostream>

int t, a, b;

void slv() {
	std::cin >> a >> b;
	
	std::cout << a + b << "\n";
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
