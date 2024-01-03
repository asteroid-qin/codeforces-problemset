#include<iostream>

int n;
long long x;
int main() {
	
	std::cin >> n >> x;
	
	int cnt = 0, val;
	char opt;
	
	for(int i = 0; i < n; i++) {
		std::cin >> opt >> val;
		if(opt == '+') x += val;
		else {
			if(x - val < 0) {
				cnt++;
			} else {
				x -= val;
			}
		}
	}
	
	std::cout << x << " " << cnt << "\n";	
	return 0;
}
