#include<iostream>

int t, n, x, k;

void slv() {
	std::cin >> n  >> k >> x;
	
	if(x < k-1 || k > n) {
		// �޽�
		std::cout << "-1\n"; 
		return ;	
	}
	int sum = (0 + k - 1) * k / 2;
	
	// �����ж�mex�Ƿ���i
	int p = x == k ? k - 1 : x;
	
	// k+1 �� x �Ƚϣ�������ζ���ȡx 
	sum += p * (n - k);
		
	std::cout << sum << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
