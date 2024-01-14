#include<iostream>
#include<algorithm>

struct Node{
	int id, val;
	bool operator<(const Node& n) const {
		if(val == n.val) return id < n.id;
		return val > n.val;
	} 
} a[200001];
int t, n, ans[200001];


void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i].val;
		a[i].id = i;
	}	
	std::sort(a+1, a+1+n);
	
	ans[0] = 0;
	
	int m = n / 2;
	long long sum = 0;
	
	for(int i = 1; i <= m; i++) {
		ans[a[i*2-1].id] = i;
		ans[a[i*2].id] = -i;
		
		sum += (long long) (a[i*2-1].val + a[i*2].val) * i;
	}
	
	if(n&1) {
		ans[a[n].id] = m + 1;
		sum += (long long)a[n].val * (m + 1);
	}
	
	std::cout << sum*2 << "\n";
	for(int i = 0; i <= n; i++) {
		std::cout << ans[i] << " ";
	}
	
	std::cout << "\n";
} 

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
