#include<iostream>

int t, l, r;
void slv() {
	std::cin >> l >> r;
	
	if(l * 2 > r) {
		std::cout << "-1 -1\n";
		return;	
	}		
	std::cout << l << " " << l * 2 << "\n";
}

int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	return 0;
}
