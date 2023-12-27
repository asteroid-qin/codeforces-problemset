#include<iostream>
#include<algorithm>

int n, t, a[100002], b[100002];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin>> a[i];

	std::sort(a, a+n);
	int k = (n - 1) / 2;
	std::cout << k << "\n";
	
	for(int i = 0, j = 1; i < k; i++, j +=2) {
		b[j] = a[i];
	}
	for(int i = k, j = 0; i < n; i++, j +=2) {
		b[j] = a[i];
	}
	
	if(n % 2==0) b[n-1] = a[n-1];
	
	for(int i = 0 ; i < n; i++) {
		std::cout << b[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	t = 1;
//	std::cin >> t;
	while(t--) slv();
	return 0;
} 
