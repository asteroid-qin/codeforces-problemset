#include<iostream> 
int n, k;

int work(int x) {
	return x * (x-1) / 2;
}

void slv() {
	std::cin >> n >> k;
	for(int i = 0; i <= n; i++) {
		// i 1   n-i  -1
		// 
		if(work(i) + work(n-i) == k  ) {
			std::cout << "YES\n";
			for(int j = 0; j < i; j++) {
				std::cout << "1 ";
			}
			for(int j = 0; j < n - i; j++) {
				std::cout << "-1 ";
			}
			return;// 2 1              0,2  1,1  2,0    // 1:0 2:1  3:3     1:0 2:1 3:3 4:6
		}			 
	} // 1 1 1 1   an=an-1+n-1  an-an-1=n-1   an-1-an-2=n-2  ...  a2-a1=1      an=n-1)*n/2     a1=0, a2=1,a3=3,a4=6
	
	std::cout << "NO\n";
}

int main() {
	int t;
	std::cin >> t;
	while(t--) slv(); 
	
	return 0;
} 
