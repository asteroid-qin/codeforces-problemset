#include<iostream>

int t, n, k;
int a[50001], b[50001];
int ans_a[50001], ans_b[50001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            a[i] = b[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            int x; std::cin >> x;
            a[x]++;
        }
        for(int i = 0; i < n; i++) {
            int x; std::cin >> x;
            b[x]++;
        }

        int len_a = 0, len_b = 0;

        for(int i = 1; i <= n; i++) {
            if(a[i] == 2 && len_a + 2 <= 2 * k) {
                ans_a[++len_a] = i;
                ans_a[++len_a] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(a[i] == 1 && len_a + 1 <= 2 * k) {
                ans_a[++len_a] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(b[i] == 2 && len_b + 2 <= 2 * k) {
                ans_b[++len_b] = i;
                ans_b[++len_b] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(b[i] == 1 && len_b + 1 <= 2 * k) {
                ans_b[++len_b] = i;
            }
        }

        for(int i = 1; i <= len_a; i++) {
            std::cout << ans_a[i] << " ";
        }
        std::cout << "\n";

        for(int i = 1; i <= len_b; i++) {
            std::cout << ans_b[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}