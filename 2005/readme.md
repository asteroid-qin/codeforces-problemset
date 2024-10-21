# A. [Simple Palindrome](https://codeforces.com/problemset/problem/2005/A)
## 问题描述
给定整数n，要求构造一个长度n的字符串s，满足：

1. s[i] 只能是 'a'、'e'、'i'、'o'、'u'。
2. s子序列是回文串的数量最少。

## 问题思路
n从1到5都比较简单：依次添加不同的字母即可。

当n=6时，假设s目前是："aeiou"，假如要放置'a'，显然这样最优："aaeiou"。因为不会多出类似 "aea" 这种子序列。

同理可以操作到n=10时，此时s是 "aaeeiioouu"，考虑n=11时，s应该是什么样子？显然还是相同放在一起。

综上：
当 n % 5 =0 时，输出 n/5个 'a'、'e'、'i'、'o'、'u'。
当 n % 5 =1 时，输出 n/5+1个'a'，n/5个 ''e'、'i'、'o'、'u'。
...

## 实现代码
```c++
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
```
## 要点
贪心