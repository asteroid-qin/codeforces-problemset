#include<iostream>
#define ld long double 

int t, n, a[200001];
long long d, h;

int main() {
	std::cout.precision(10); std::cout.setf(std::ios::fixed);
	
	std::cin >> t;
	while(t--) {
		std::cin >> n >> d >> h;
		for(int i = 0; i < n; i++) std::cin >> a[i];
		
		ld sum = (ld)d * h / 2.0;
		
		for(int i = n - 2; i >= 0; i--) {
			if(a[i+1] < a[i] + h) {
				ld x = a[i+1] - a[i];
				sum += ((h-x) / h * d + d) * x / 2.0;
			} else {
				sum += (ld)d * h / 2.0;
			}
		}
		
		std::cout << sum << "\n";
	}
	return 0;
}
