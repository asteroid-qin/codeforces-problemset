#include<iostream>

int a[51];
int main(){
	int t, n, m;
	
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		std::string b(m, 'B');
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		
		for(int i = 0; i < n; i++) {
			int x = a[i], y = m + 1 - a[i];
			if(x > y) std::swap(x, y);
			if(b[x-1]=='A') b[y-1] = 'A';
			else b[x-1] = 'A';
		}
		
		std::cout << b << "\n";
	}
	
	return 0;
} 
