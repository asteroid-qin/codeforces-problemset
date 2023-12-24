#include<iostream>

const int N = 100000;
int t, d, p[N+9], idx;
bool np[N+9];

void init() {
	for(int i = 2; i <= N; i++) {
		if(np[i]) continue;
		p[++idx] = i;
		for(long long j = (long long)i * i; j <= N; j += i) {
			np[j] = true;
		}
	}
}
int main() {
	init();
	std::cin >> t;
	while(t--) {
		std::cin >> d;
		// 找第一个 
		int i = 1;
		while(i <= idx && p[i] - 1 < d) i++;
		
		int x = p[i];
		
		// 找第二个 
		i++;
		while(i <= idx && p[i] - x < d) i++;
		int y = p[i];
		
		std::cout << (long long) x * y << "\n";
	}
	return 0; 
} 
