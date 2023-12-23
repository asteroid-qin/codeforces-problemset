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
	
	// 一个数 
	for(int i = 0; i < 5; i++) {
		if(cnt[one[i]] != 0) {
			std::cout << "1\n" << one[i] << "\n";
			return;
		}
	}	
	// 两个数 
	for(int i = 0; i < 4; i++) {
		if(cnt[two[i]] > 1) {
			std::cout << "2\n";
			std::cout << two[i] << two[i] << "\n";
			return;
		}
	}
	
	// 现在开始长度为2-4
	// 长度2（因为都是奇数，长度2不能删掉）
	if(n == 2) {
		std::cout << n << "\n" << s << "\n";
		return;
	} 
	
	// 长度3：235，237，257，357.
	// 其中包含2的必然有25 52 或者 27 72 。长度4在这步也被解决。 
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
	// 不包含2的长度为3的只有 3 5 7。因为57 75 
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
