#include<iostream>


int t, n, a[200001];
void slv() {
	std::cin >> n;
	
	int x, y, z; // n >= 3
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) x = i;
		else if(a[i] == 2) y = i;
		else if(a[i] == n) z = i;
	}
	
	if(x > y) std::swap(x, y);
	
	// x < y
	if(z > y) {
		std::cout << y << " " << z << "\n";
	} else if(z < x){
		std::cout << z << " " << x << "\n";
	} else {
		std::cout << z << " " << z << "\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
