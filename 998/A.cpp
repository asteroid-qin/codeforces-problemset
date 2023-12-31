#include<iostream>

int n, a[1001];
int main(){
	std::cin >> n;
	
	int idx = - 1, mi = 1001, sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] < mi) {
			mi = a[i];
			idx = i;
		}
		
		sum += a[i];
	}
	
	if(n == 1 || sum == a[idx] * 2) {
		std::cout << "-1\n";
		return 0;
	}
	
	std::cout << n-1 << "\n";
	for(int i = 0; i < n; i++) {
		if(i != idx) {
			std::cout << i + 1 << " ";
		}
	}
	std::cout << "\n";
	return 0;
} 
