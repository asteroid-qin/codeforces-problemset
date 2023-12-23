#include<iostream>

int t, n, a[100001];

void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	// ��У��
	if(n == 1) {
		std::cout << "-1\n";
		return;
	}
	
	// ͷβ 
	if(a[1] != a[2] || a[n] != a[n-1]) {
		std::cout << "-1\n";
		return;
	}
	
	for(int i = 2; i < n; i++) {
		if(a[i] != a[i - 1] && a[i + 1] != a[i]) {
			std::cout << "-1\n";
			return;
		}
	}
	 

	int i = 1;
	while(i <= n) {
		// ��j��ʹ��a[i] = a[i+1] = ... = a[j]
		int j = i + 1;
	 	while(j <= n && a[j] == a[i]) j++;
	 	j--;

		// �����
		for(int k = i; k <= j; k++) {
			if(k == i) std::cout << j << " ";
			else std::cout << k - 1 << " ";
		}	 
		i = j + 1;
	}
	std::cout << "\n";
}


int main() {
	std::cin >> t;
	while(t--) {
		slv(); 
	}
	
	return 0;
}
