#include<iostream>

int t, n, x, k;

void slv() {
	std::cin >> n  >> k >> x;
	
	if(x < k-1 || k > n) {
		// 无解
		std::cout << "-1\n"; 
		return ;	
	}
	int sum = (0 + k - 1) * k / 2;
	
	// 现在判断mex是否是i
	int p = x == k ? k - 1 : x;
	
	// k+1 与 x 比较，如论如何都是取x 
	sum += p * (n - k);
		
	std::cout << sum << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
