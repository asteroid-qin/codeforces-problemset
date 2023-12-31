#include<iostream>
#include<vector>
#include<algorithm>

int t, n, a[200001];
int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a+n);
	
	std::vector<int> p, q;
	for(int i = 2; i < n; i++) {
		if(a[i] == a[i-1] && a[i] == a[i-2]) {
			std::cout << "NO\n";
			return 0;
		}
	}  
	
	q.push_back(a[0]);
	for(int i = 1; i < n; i++) {
		if(a[i] == a[i-1]) {
			p.push_back(a[i]);
		} else {
			q.push_back(a[i]);
		}
	}
		
	std::cout << "YES\n";
	std::cout << p.size() << "\n";
	for(int v : p) std::cout << v << " ";
	std::cout << "\n";
	
	std::cout << q.size() << "\n";
	for(int i = q.size() - 1; i >= 0; i--)
		std::cout << q[i] << " ";
	std::cout << "\n";
	return 0;
}
