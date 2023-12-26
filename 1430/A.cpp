#include<iostream>

int n, t;
int x, y, z;

bool check() {
	for(int i = 0; i <= 1000 && 7 * i <= n; i++) {
		for(int j = 0; j <= 1000 && 7 * i + 5 * j <= n; j++) {
			if((n - 7 * i - 5 * j) % 3 == 0) {
				x = (n - 7 * i - 5 * j) / 3;
				y = j;
				z = i;
				return true;
			}
		}
	}
	return false;
} 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		if(check()) std::cout << x << " " << y << " " << z << "\n";
		else std::cout << "-1\n";
	}
	return 0;
} 
