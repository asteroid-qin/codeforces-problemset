#include<iostream>

int n;
int main() {
	std::cin >> n;
	int a = 0;
	for(int i = 0; i < n; i++) {
		int x; std::cin >> x;
		if(x == 1) a++;
	}
	int c = std::min(a, n-a);
	
	std::cout << c + (a - c) / 3 << "\n";
	
	return 0;
}
