#include<iostream>

int n, a, b;
int main() {
	std::cin >> n >> a >> b;
	
	if(a * b < n) {
		std::cout << "-1\n";
		return 0;
	}
	
	int x = 1, y = 2;
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			int cur = i + j;
			
			if(cur & 1) {
				if(y <= n) {
					std::cout << y << " ";
					y += 2;
				} else {
					std::cout << "0 ";
				}
			} else {
				if(x <= n) {
					std::cout << x << " ";
					x += 2;
				} else {
					std::cout << "0 ";
				}
			} 
		}
		
		std::cout << "\n";
	}
	return 0;
}
