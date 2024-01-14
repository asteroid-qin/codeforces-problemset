#include<iostream>
#include<algorithm>

struct Node{
	int id, x, k;
	
	bool operator<(const Node& n) {
		if(k == n.k) return id < n.id;
		return k < n.k;
	}
} q[100000];
int t, n, a[2001], b[2001], c[2001], m, cnt[2001], ans[100000];
int k, x;

void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	
	int mx = 0;
	while(true) {
		for(int i = 1; i <= n; i++) {
			cnt[i] = 0;
		}
		
		for(int i = 1; i <= n; i++) {
			cnt[b[i]]++;
		}
		
		for(int i = 1; i <= n; i++) {
			c[i] = cnt[b[i]];
		}
		
		bool eq = true;
		for(int i = 1; i <= n; i++) {
			if(b[i] != c[i]) {
				eq = false;
			}
			b[i] = c[i];
		}
		
		if(eq) break;
		mx++;		
	}
	
	for(int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		std::cin >> q[i].x >> q[i].k;
		q[i].id = i;
		q[i].k = std::min(q[i].k, mx);
	}
	
	std::sort(q, q+m);
	
	for(int i = 0, j = 0; i < m; i++) {
		while(j < q[i].k) {
			for(int p = 1; p <= n; p++) {
				cnt[p] = 0;
			}
			
			for(int p = 1; p <= n; p++) {
				cnt[b[p]]++;
			}
			
			for(int p = 1; p <= n; p++) {
				c[p] = cnt[b[p]];
			}
			
			for(int p = 1; p <= n; p++) {
				b[p] = c[p];
			}
			
			j++;
		}
		
		ans[q[i].id] = b[q[i].x];
	}
	
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << "\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	
	return 0;
}
