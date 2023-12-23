#include<iostream>
#include<deque>

int t, n;

void slv() {
	std::cin >> n;
	int mi = 2e5;
	
	std::deque<int> dq;
	for(int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		mi = std::min(mi, x);
		if(x == mi) dq.push_front(x);
		else dq.push_back(x);
	}
	
	while(!dq.empty()) {
		int x = dq.front();
		dq.pop_front();
		std::cout << x << " ";
	}
	std::cout << "\n";
}
int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
}
