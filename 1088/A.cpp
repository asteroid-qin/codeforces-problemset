#include<iostream>

int x;
int main(){
	std::cin >> x;
	if(x == 1) {
		std::cout << "-1\n";
	} else {
		std::cout << x << " " << x << "\n";
	}
	return 0;
} 
