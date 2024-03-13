#include<iostream>
#include<vector>
int t, n, a[200001];
char ans[200001];

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> b;

        for(int i = n - 1; i >= 0; i--) {
            int j = 0;
            while(j < b.size() && b[j] != a[i]) j++;
            if(j == b.size()) {
                b.push_back(a[i]-1);
            } else {
                b[j]--;
            }
            ans[i] = (char) ( j + 'a');
        }

        for(int i = 0; i < n; i++) {
            std::cout << ans[i];
        }
        std::cout << "\n";
    }
    return 0;
}