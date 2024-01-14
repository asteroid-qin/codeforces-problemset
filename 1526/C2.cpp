#include<iostream>
#include<queue>

int n, a[200000];
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> a[i];
	
	int ans = 0;
	long long sum = 1;
	for(int i = 0; i < n; i++) {
		ans++;
		sum += a[i];
		pq.push(a[i]);
		
		while(sum < 1 && !pq.empty()) {
			int x = pq.top(); pq.pop();
			ans--;
			sum -= x;
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}

