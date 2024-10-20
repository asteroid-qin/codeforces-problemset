#include<iostream>

int t, a, b;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> a >> b;
        if(a & 1) {
            std::cout << "NO\n";
            continue;
        }

        int x = a / 2 + b;
        if((x & 1) && a == 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}