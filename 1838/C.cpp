#include<iostream>

int t, n, m, a[1000];

void slv() {
	std::cin >> n >> m;
	
	// ����m��ż�� 
	if(m % 2 == 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << i * m + j + 1 << " ";
			}
			std::cout << "\n";
		}
		return ;
	}
	
	
	// ��һ�� 
	for(int i = 0; i < m; i++) {
		a[i] = i + 1;
		std::cout << i + 1 << " ";
	}
	std::cout << "\n";
	
	// �ڶ����Ժ� 
	for(int i = 1; i < n; i++) {
		// �����ƶ�1λ
		int x = a[0] + m;
		for(int j = 1; j < m; j++) {
			a[j-1] = a[j] + m;
		}
		a[m-1] = x;
		
		// ���
		for(int j = 0; j < m; j++) {
			std::cout << a[j] << " ";
		} 
		std::cout << "\n";
	}
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
