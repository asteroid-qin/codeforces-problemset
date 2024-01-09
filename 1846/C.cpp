#include<iostream>
#include<algorithm>

int t, n, m, h, a[200001];

struct Node {
	int id, a;
	long long b;
	
	bool operator<(const Node& n) const {
		if(a == n.a) {
			if(b == n.b) return id < n.id;
			return b < n.b;
		}
		return a > n.a;
	}
} b[200001];

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> m >> h;
		for(int i = 1; i <= n; i++) {
			b[i].id = i;
			
			for(int j = 0; j < m; j++) {
				std::cin >> a[j];
			}
			
			std::sort(a, a+m);
			
			int sum = 0, cnt = 0;
			long long cur = 0;
			
			for(int j = 0; j < m && sum + a[j] <= h; j++) {
				sum += a[j];
				cnt++;
				cur += sum;
			} 
			
			b[i].a = cnt;
			b[i].b = cur;
		}
		
		std::sort(b+1, b+n+1);
		
		for(int i = 1; i <= n; i++) {
			if(b[i].id == 1) {
				std::cout << i << "\n"; 
				break;
			}
		}
	}
	return 0;
}
