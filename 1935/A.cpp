#include<iostream>
#include<algorithm>

int t, n;
std::string s;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> s;
        std::string a = s;
        std::reverse(a.begin(), a.end());

        if(s <= a) {
            std::cout << s << "\n";
        } else {
            std::cout << a + s << "\n";
        }
    }
    return 0;
}