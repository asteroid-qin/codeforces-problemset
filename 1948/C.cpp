#include<iostream>

int t, n;
char mp[3][200001];

bool check() {
    int x = 1, y = 1;
    while(2 - x + n - y > 1) {
        char right_arrow = mp[x][y + 1];
        if(right_arrow == '>') {
            y += 2;
        } else {
            char top_arrow = mp[x ^ 1 ^ 2][y];
            if(top_arrow == '<') {
                return false;
            } else {
                x ^= 1 ^ 2;
                y = y + 1;
            }
        }
    }
    return true;
}

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= n; j++) {
                std::cin >> mp[i][j];
            }
        }

        if(check()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}