#include<iostream>
 
int main(){
    int t, x, k;
    std::cin >> t;
    while(t--) {
        std::cin >> x >> k;
        if(x % k == 0) {
            std::cout << "2\n" << x - 1 << " " << "1\n";
        } else {
            std::cout << "1\n" << x << "\n";
        }
    }
    
}
