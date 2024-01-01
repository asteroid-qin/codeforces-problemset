#include<iostream>

int n, m, a[101], b[101]; 
int main() {
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	for(int i = 0; i < m; i++) std::cin >> b[i];
	
	bool eq = true;
	for(int i = 1; i < m; i++) {
		if(b[i] != b[i-1]) {
			eq = false;
			break;
		}
	}
		
	if(!eq) {
		std::cout << "YES\n";
		return 0;
	}	
	
	bool np = true;
    if(a[0]==0) a[0] = b[0];
	for(int i = 1; i < n; i++) {
		if(a[i] == 0) a[i] = b[0];
		
		if(a[i-1] > a[i]) {
			np = false;
			break;
		}
	}
	
	if(np) std::cout << "NO\n";
	else std::cout << "YES\n";
		
	return 0;
}
