# 问题描述
给定偶数n和字符串s，可以执行两种操作：
1. 将当前s反转。
2. 向当前s后面加上反转后的s。

现在求执行n次后，最小字母顺序的s

# 问题思路
为了让字母顺序最小，显然应该尽可能减少s的长度：也就是多的使用操作1。

于是发现，如果s的字母顺序小于等于反转后的s，那么直接输出s即可：因为n是偶数，所以执行n/2次操作1就可以得到原s。
否则，需要将s反转n-1次，最后一次执行操作2，得到反转s+s。

# 实现代码
```c++
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
```
# 要点
贪心