#include<iostream>

int t;
int n, a[100];

void slv() {
	std::cin >> n;
		
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	bool sym = true;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			std::cout << "0\n";
			
			return;
		}
		
		if(a[i] < 0) sym = !sym; 
	}
	
	if(sym) {
		std::cout << "1\n1 0\n";
	} else {
		std::cout << "0\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
}
