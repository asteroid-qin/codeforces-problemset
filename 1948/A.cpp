#include<iostream>

int t, n;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        if(n & 1) {
            std::cout << "NO";
        } else {
            std::cout << "YES\n";
            for(int i = n / 2; i > 0; i--) {
                std::cout << "BAA";
            }
        }

        std::cout << "\n";
    }
    return 0;
}