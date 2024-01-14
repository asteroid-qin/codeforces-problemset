#include<iostream>
#include<algorithm> 
#define ll long long
int t, n, arr[200001];
struct Node {
	int a, b;
	bool operator<(const Node& n) const{
		return a < n.a;
	}
} pr[200001];
ll ans;

void work(int l, int r) {
	if(l >= r) return;
	int mid = (l+r)/2;
	work(l, mid);
	work(mid+1, r);
	
	int i = l, j = mid + 1, p = l;
	while(i <= mid && j <= r) {
		if(pr[i].b <= pr[j].b) {
			arr[p] = pr[i].b;
			i++;
		} else {
			arr[p] = pr[j].b;
			ans += mid - i+1;
			j++;
		}
		p++;
	}
	
	while(i <= mid) {
		arr[p++] = pr[i++].b;
	}
	while(j <= r) {
		arr[p++] = pr[j++].b;
	}
	
	p = l;
	while(p <= r) {
		pr[p].b = arr[p];
		p++;
	}
}

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> pr[i].a >> pr[i].b;
	}
	std::sort(pr, pr + n);
	
	ans = 0;
	work(0, n-1);	
	std::cout << ans << "\n";
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 



