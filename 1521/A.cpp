#include<iostream>

long long a, b, t;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> a >> b;
		
		
		if(b == 1) {
			std::cout << "NO\n";
			continue;
		} 

		std::cout << "YES\n";
		
		if(b == 2) {
			std::cout << a << " " << a*3 << " " << a*4 << "\n";
			continue;
		} 
		
		long long x = a, y = (b-1)*a, z = a*b;
		std::cout << x << " " << y << " " << z << "\n";
	}
	return 0;
}
