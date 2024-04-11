#include<iostream>
#include<algorithm>

int t, n, a[200001], b[200001], c[200001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
            c[i] = i;
        }
        for(int i = 1; i <= n; i++) std::cin >> b[i];

        std::sort(c+1, c+n+1, [&](const int x, const int y) {
            return a[x] < a[y];
        });

        for(int i = 1; i <= n; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        for(int i = 1; i <= n; i++) {
            std::cout << b[c[i]] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}