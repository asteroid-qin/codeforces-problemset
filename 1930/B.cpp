#include<iostream>

int t, n;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        int l = 1, r = n;
        for(int i = 1; i <= n; i++) {
            if(i & 1) {
                std::cout << l << " ";
                l++;
            } else {
                std::cout << r << " ";
                r--;
            }
        }
        std::cout << "\n";
    }
    return 0;
}