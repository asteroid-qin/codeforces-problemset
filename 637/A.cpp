#include<iostream>
#include<map>

int n, a[1000];

int main() {
	std::cin >> n;
	
	std::map<int, int> mp;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mp[a[i]]++;
	}
	
	int cnt = 0;
	for(auto it : mp) {
		cnt = std::max(cnt, it.second);
	}	
	
	mp.clear();
	for(int i = 0; i < n; i++) {
		mp[a[i]]++;
		if(mp[a[i]] == cnt) {
			std::cout << a[i] << "\n";
			return 0;
		}
	}
	return 0;
}
