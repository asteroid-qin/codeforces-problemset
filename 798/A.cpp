#include<iostream>

std::string s;
int main() {
	std::cin >> s;
	int n = s.size();
	int i = 0, j = n - 1, tot = 0;
	while(i < j) {
		if(s[i] != s[j]) tot++;
		i++; j--;
	}
	
	if(tot == 1 || (tot == 0 && (n & 1))) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
} 
