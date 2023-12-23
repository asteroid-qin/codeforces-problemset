#include<iostream>

int t, n;

void slv() {
	std::cin >> n;
	if(n > 4) {
		std::cout << "Alice\n";
	} else {
		std::cout << "Bob\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
