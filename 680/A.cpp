#include<iostream>

int n, a[5];
int main() {
	n = 5;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int sum = 0, mx = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		
		int cnt =  0;
		for(int j = 0 ; j < n; j++) {
			if(a[i] == a[j]) cnt++;
		}
		
		if(cnt < 2) continue;
		cnt = std::min(cnt, 3);
		
		mx = std::max(mx, cnt * a[i]);
	}	
	
	std::cout << sum -  mx << "\n";
	return 0;
} 
