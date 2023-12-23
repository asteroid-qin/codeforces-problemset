#include<iostream>

int t, n;
std::string s;

// 计算至少需要几个1 
int get() {
	int i = 0, j = n - 1;
	int k = 0;
	while(i < j) {
		if(s[i++] != s[j--]) {
			k++;
		}
	}
	return k;
}

void slv() {
	std::cin >> n >> s;
	int k = get();
	for(int i = 0; i < k; i++) std::cout << '0';
	std::cout << '1'; 
	
	if(n & 1) {
		if(k == 0) {
			for(int i = k+1; i <= n; i++) {
				std::cout << '1';
			}
			std::cout << '\n';
		} else {
			// 后面就是(n/2 -k ) * 2 - 1 个1，后续都是0
			for(int i = (n / 2 - k ) * 2 + 1; i > 0; i--) std::cout << '1';
			for(int i = k + 1 + (n / 2 - k ) * 2 + 1; i <= n; i++) std::cout << '0';
			std::cout << '\n';
		}
		return;
	}	
	
	//后面就是 (n/2 -k ) 个01，后续都是0
	for(int i = n / 2 - k; i > 0; i--) std::cout << "01";
	for(int i = n - k + 1; i <= n; i++) std::cout << '0';
	std::cout << '\n';
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
