#include<iostream>

int n, x, a[3];
int main() {
	std::cin >> n >> x;
	n %= 6;
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) a[j] = 0;
		a[i] = 1;
		
		for(int j = 1; j <= n; j++) {
			if(j&1) std::swap(a[0], a[1]);
			else std::swap(a[2], a[1]);
		}
		
		if(a[x] == 1) {
			std::cout << i << "\n";
			break;
		}
	}
	return 0;
} 
