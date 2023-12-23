#include<iostream>



int t, m, n;

int get(int x, int y) {
	int p = x == m ? 1 : x;
	int q = y == n ? 1 : y;
	if(p == 1 && q == 1) {
		return 2;
	} 
	
	if(p == 1 || q == 1) {
		return 3;
	}
	return 4;
}

void slv() {
	int x1, x2, y1, y2;
	std::cin >> m >> n >> x1 >> x2 >> y1 >> y2;
	std::cout << std::min(get(x1, x2), get(y1, y2)) << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
