#include <iostream>

int t, n;
std::string a, b, c;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> a >> b >> c;
        bool has = false;
        for(int i = 0; i < n; i++) {
            if( (a[i] == b[i] && a[i] != c[i]) ||
                    (a[i] != c[i] && b[i] != c[i]) ) {
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