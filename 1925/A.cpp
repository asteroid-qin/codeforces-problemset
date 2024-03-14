#include<iostream>

int t, n, k;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;
        while(n--) {
            for(int i = 0; i < k; i++) {
                std::cout << (char)('a' + i);
            }
        }
        std::cout << "\n";
    }
    return 0;
}