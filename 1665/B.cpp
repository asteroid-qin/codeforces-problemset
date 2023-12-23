#include<iostream>
#include<algorithm>

int t, n, a[100000];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		
		int k = 0;
		int i = 0;
		while(i < n) {
			int j = i+1;
			while(j < n && a[j] == a[i]) j++;
			
			// [i, j-1]��a[i]���
			k = std::max(k, j-i);
			
			// ��ת
			i = j; 
		} 
		
		int ans = 0;
		while(k < n) {
			// �ƶ� cnt �� 
			int cnt = std::min(k, n - k);
			
			// k�����ƶ�
			k += cnt;
			
			// ans��Ҫ�ƶ�+���� 
			ans += cnt + 1; 
		}
		std::cout << ans << "\n";
	}
	return 0;
}
