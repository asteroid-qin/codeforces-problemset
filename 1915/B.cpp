#include<iostream>

int t, n, a[3];

char slv() {
	for(int i = 0; i < 3; i++) a[i] = 0;
	
	for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++) 
	{
		char ch;
		std::cin >> ch;
		
		if(ch != '?') a[ch-'A']++;
	}
	
	for(int i = 0; i < 3; i++) {
		if(a[i] != 3) return i + 'A';
	}
	return 'A';
}
int main(){
	std::cin >> t;
	while(t--) {
		std::cout << (char)slv() << "\n";
	}
	return 0;
} 
