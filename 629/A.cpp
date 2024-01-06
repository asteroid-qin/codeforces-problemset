#include<iostream>

int n;
char a[101][101];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		int cnt = 0; 
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'C') cnt++;
		}
		
		ans += cnt * (cnt - 1) / 2;
	}
	
	for(int j = 0; j < n; j++) {
		int cnt = 0; 
		for(int i = 0; i < n; i++) {
			if(a[i][j] == 'C') cnt++;
		}
		
		ans += cnt * (cnt - 1) / 2;
	}
	
	std::cout << ans << "\n";
	return 0;
}
