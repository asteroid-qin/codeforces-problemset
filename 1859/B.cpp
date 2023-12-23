#include<iostream>
#include<vector>

int t, n;
void slv() {
	std::cin >> n;
	std::vector<int> fir(n), sec(n);
	
	for(int i = 0; i < n; i++) {
		int m; std::cin >> m;
		int a = 1e9+7, b = 1e9+7;
		for(int j = 0; j < m; j++) {
			int x; std::cin >> x;
			if(x < a) {
				b = a;
				a = x;
			} else if(x == a) {
				b = x;
			} else if(x < b){
				b = x;
			}
		}
		fir[i] = a;
		sec[i] = b;
	}
	
	// 得到最小first 和 second 
	int min_fir = 1e9 + 7, min_sec= 1e9 +7;
	for(int i = 0; i < n; i++) {
		if(min_fir > fir[i]) min_fir = fir[i];
		if(min_sec > sec[i]) min_sec = sec[i]; 
	}
	
	// 处理sec
	long long sum_sec = 0;
	for(int i = 0; i < n; i++) {
		sum_sec += sec[i];
	} 
	std::cout << min_fir + sum_sec - min_sec << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
