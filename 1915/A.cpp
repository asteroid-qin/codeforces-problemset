#include<iostream>

int t, n;
int main(){
	std::cin >> t;
	while(t--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if(a == b) std::cout << c << "\n";
		if(a == c) std::cout << b << "\n";
		if(b == c) std::cout << a << "\n";
	}
	return 0;
} 
