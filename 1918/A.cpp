#include<iostream>

int t, n, m;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m;
        std::cout << m / 2 * n << "\n";
    }
    return 0;
}