#include<iostream>

int t, r, b, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> r >> b;
		int x = (r + b) / (b + 1);
		int cnt = x * (b + 1) - r;
		
		for(int i = 1; i <= n; ) {
			int cur_x = x;
			if(cnt > 0) {
				cur_x--;
				cnt--;
			}		
			for(int j = cur_x;j > 0; j--) {
				std::cout << "R";
			}			
			i += cur_x;
				
			if(b > 0) {
				std::cout << "B";
				b--;
				i++;
			}
		}
		std::cout << "\n";
	}
	return 0;
} 
