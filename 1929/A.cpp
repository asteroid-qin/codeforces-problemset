#include<iostream>

int t, n, a;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        int p = -1, q = 2e9;
        for(int i = 0; i < n; i++) {
            std::cin >> a;
            p = std::max(p, a);
            q = std::min(q, a);
        }

        std::cout << p -  q << "\n";
    }

    return 0;
}