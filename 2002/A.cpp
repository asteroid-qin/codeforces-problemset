#include<iostream>

int t, n, m, k;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m >> k;
        std::cout << std::min(n, k) * std::min(m, k) << "\n";
    }
    return 0;
}