#include<iostream>

int t, n;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        int cnt[5] = {0};
        char key[5] = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < 5; i++) {
            cnt[i] = n / 5;
        }
        n -= n / 5 * 5;
        for(int i = 0; i < n; i++) {
            cnt[i]++;
        }
        for(int i = 0; i < 5; i++) {
            while(cnt[i]--) std::cout << key[i];
        }
        std::cout << "\n";
    }
    return 0;
}