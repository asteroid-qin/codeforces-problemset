#include<iostream>

void slv() {
	int n;
	std::cin >> n;
	if (n == 1) {
        std::cout << "1\n";
        return;
    }
    
	if(n&1) {
		std::cout << "-1\n";
		return;
	} 
	std::cout << n;
	for(int p = 1, q = n - 2; p < n; p += 2, q -= 2) {
		std::cout << " " << p;
		if(q > 0) std::cout << " " <<  q; 
	}
	
	std::cout << "\n";
}
int main() {
	int t;
	std::cin >> t;
	while(t--) slv();
	return 0;
}
