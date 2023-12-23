#include<iostream>

int t;
long long n, k, b, s, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k >> b >> s;

		

		if( k*b <= s && s <= (n-1)*(k-1)+k*b+k-1 )	{
			for(int i = 0; i < n; i++) {
				a[i] = 0;	
			}
			a[0] = k*b;
			s -= k*b;
			
			for(int i = 0; i < n; i++) {
				long long x = std::min(s, k - 1);
				s -= x;
				a[i] += x;
			}
			
			for(int i = 0; i < n; i++) {
				std::cout << a[i] << " "; 
			}
			std::cout << "\n";
			
			continue;
		}
		
		std::cout << "-1\n";
	}
	return 0;
}
