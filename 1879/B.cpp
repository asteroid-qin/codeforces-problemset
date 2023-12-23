#include<iostream>


int main() {
	int t, n;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		
		int a, b;
		long long sum_row = 0, sum_col = 0;
		int min_row = 1e9, min_col = 1e9;
		 
		for(int i = 0; i < n; i++) {
			std::cin >> a;
			sum_row += a;
			min_row = std::min(min_row, a);
		}
		
		for(int i = 0; i < n; i++) {
			std::cin >> b;
			sum_col += b;
			min_col = std::min(min_col, b);
		}
		
		std::cout << std::min(sum_row + (long long)n * min_col ,  sum_col + (long long) n * min_row  ) << "\n";
	}
	
	return 0;
}
