#include<iostream>

int t, n, a[1000][1000], b[1000];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		b[i] = (1 << 30) - 1;
	}
	
	for(int i = 0; i < n; i++) 
	for(int j = 0; j < n; j++)
	{
		std::cin >> a[i][j];
		if(i != j) {
			b[i] &= a[i][j];
			b[j] &= a[i][j];
		}
	}
	
	bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && (b[i] | b[j]) != a[i][j]){
                ok = false;
            }
        }
    }
    
    if(!ok){
        std::cout<<"NO\n";
        return;
    }
    
    std::cout<<"YES\n";
    for(int i = 0; i < n; i++){
        std::cout << b[i] << " ";
    }
    
    std::cout << "\n";
}
int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
} 
