#include<iostream>

int n, t, a[100];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	for(int i = 0; i < n; i += 2) {
		std::cout << a[i+1] * -1 << " " << a[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
