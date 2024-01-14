#include<iostream>
#include<cmath>
int t, n, a[3];

bool slv() {
	std::cin >> n;
	int x;
	long long sum = 0;
	
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		sum += x;
	}
	
	long long y = sqrt(sum);
	return sum == y * y;
}
int main(){
	std::cin >> t;
	while(t--) {
		if(slv()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
} 
