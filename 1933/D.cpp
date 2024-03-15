#include<iostream>
#include<algorithm>

int t, n, a[100001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a, a + n);
        if(a[0] != a[1]) {
            std::cout << "YES\n";
            continue;
        }

        bool has = false;
        for(int i = 1; i < n; i++) {
            if(a[i] % a[0] != 0) {
                has = true;
                break;
            }
        }

        if(has) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}