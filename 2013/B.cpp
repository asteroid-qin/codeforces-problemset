#include<iostream>

int t, n, a;

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; i++) {
            std::cin >> a;
            sum += a;
            if(i == n - 1) {
                sum -= 2 * a;
            }
        }

        std::cout << sum << "\n";
    }
    return 0;
}