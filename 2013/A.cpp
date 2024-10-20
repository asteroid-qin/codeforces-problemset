#include<iostream>

int t, n, x, y;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> x >> y;
        int a = std::min(x, y);

        std::cout << (n + a - 1) / a << "\n";
    }
    return 0;
}