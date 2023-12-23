#include<iostream>
#include<vector>

int t, n;
std::string s;

int one[] = {1, 4, 6, 8, 9};
int two[] = {2, 3, 5, 7};

void slv() {
	std::cin >> n >> s;
	std::vector<int> cnt(10, 0);
	for(char ch : s) cnt[ch-'0']++;
	
	// һ���� 
	for(int i = 0; i < 5; i++) {
		if(cnt[one[i]] != 0) {
			std::cout << "1\n" << one[i] << "\n";
			return;
		}
	}	
	// ������ 
	for(int i = 0; i < 4; i++) {
		if(cnt[two[i]] > 1) {
			std::cout << "2\n";
			std::cout << two[i] << two[i] << "\n";
			return;
		}
	}
	
	// ���ڿ�ʼ����Ϊ2-4
	// ����2����Ϊ��������������2����ɾ����
	if(n == 2) {
		std::cout << n << "\n" << s << "\n";
		return;
	} 
	
	// ����3��235��237��257��357.
	// ���а���2�ı�Ȼ��25 52 ���� 27 72 ������4���ⲽҲ������� 
	if(cnt[2] && cnt[5]) {
		std::cout << "2\n"; 
		for(char ch : s) {
			if(ch != '5' && ch != '2') continue;
			std::cout << ch;
		}
		std::cout << "\n";
		return;
	}
	
	if(cnt[2] && cnt[7]) {
		std::cout << "2\n"; 
		for(char ch : s) {
			if(ch != '7' && ch != '2') continue;
			std::cout << ch;
		}
		std::cout << "\n";
		return;
	}
	// ������2�ĳ���Ϊ3��ֻ�� 3 5 7����Ϊ57 75 
	std::cout << "2\n"; 
	for(char ch : s) {
		if(ch != '5' && ch != '7') continue;
		std::cout << ch;
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
