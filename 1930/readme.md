# B. [Permutation Printing](https://codeforces.com/problemset/problem/1930/B)
## 问题描述
给定整数n，要求构造1-n的全排列p，满足：
1. p不存在i、j使得 p[i] 被 p[j] 整除 且 p[i+1] 被 p[j+1]整除（i不等于j）

## 问题思路
对于x（n/2 < x <= n)，不存在数被它整除。

将x均匀地放置即可。

## 实现代码
```c++
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
```

## 要点
均匀放置找不到被整除数的数