#include<iostream>

int t, n, m; 
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m;
		
		if(m == 1) {
			std::cout << "YES\n";
			for(int i = 1; i <= n; i++) {
				std::cout << i << "\n";
			}
			continue;
		}
		// �ж��ٸ�������(n+m)/2 �� 
		int k = (n*m)/2;
		
		if(k % m != 0) {
			std::cout << "NO\n";
			continue;
		} 
		
		int p = k / m;
		std::cout << "YES\n";
		
		// �����k/m�� m �� ������ ��ͬ�����ż��
		for(int i = 0, x = 1; i < p; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << x << " ";
				x += 2;
			}
			std::cout << "\n";
		}
		
		for(int i = 0, x = 2; i < p; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << x << " ";
				x += 2;
			}
			std::cout << "\n";
		}
	}
	return 0;
}
