# 问题描述
给定整数n和k，要求构造字符串s，满足：
1. 记长度n的每位都有k种可能的得到字符串t，要求所有t都可以在s中作为子序列被找到。
2. s的长度最小。

# 问题思路
根据测试用例，有个猜想：s的长度 >= n * k。

不妨令s为n个'a'到'a'+k-1个字符拼接而成。

判断他是否满足题目要求？
显然一定是满足的，无论以任何字母开头，后面都有n-1种'a'到'a'+k-1的选择。


# 实现代码
```c++
#include<iostream>

int t, n, k;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;
        while(n--) {
            for(int i = 0; i < k; i++) {
                std::cout << (char)('a' + i);
            }
        }
        std::cout << "\n";
    }
    return 0;
}
```

# 要点
感觉