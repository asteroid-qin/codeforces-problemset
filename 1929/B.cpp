#include<iostream>

int t, n, k;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;

        if(4 * n - 4 >= k) {
            std::cout << (k + 1) / 2 << "\n";
        } else {
            std::cout << k - 2 * n + 2 << "\n";
        }
    }
    return 0;
}