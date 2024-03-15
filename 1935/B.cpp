#include<iostream>

int t, n, a[100001];
bool has[100001];

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        // 求x: 表示a的MEX
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int x = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            has[a[i]] = true;
            while(has[x]) x++;
        }

        // 求idx：[0, idx]的MEX等于x
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int y = 0, idx = -1;
        for(int i = 0; i < n; i++) {
            has[a[i]] = true;
            while(has[y]) y++;
            if(y == x) {
                idx = i;
                break;
            }
        }

        // 求z：表示[idx+1, n]的MEX
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int z = 0;
        for(int i = idx + 1; i < n; i++) {
            has[a[i]] = true;
            while(has[z]) z++;
        }

        if(z == x) {
            std::cout << "2\n";
            std::cout << 1 << " " << idx + 1 << "\n";
            std::cout << idx + 2 << " " << n << "\n";
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}