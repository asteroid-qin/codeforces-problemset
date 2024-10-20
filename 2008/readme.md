# A. [Sakurako's Exam](https://codeforces.com/problemset/problem/2008/A)
## 问题描述
给定数组c和整数a、b。c由a个1和b个2组成。

现在可以执行任意次操作：将c[i]替换为-c[i]。

问：是否可以使得数组c的和等于0？

## 问题思路
这个问题可以转化为：能否将数组c分为两部分，使得两部分的和相等？

首先保证这个和存在，令d = sum / 2。显然得保证a是偶数。

当a >= 2 * b 时，显然输出YES。

当a < 2 * b时：尝试用到所有的a和部分b来构造d

如果 d - a是偶数，输出YES。
否则，判断a是否大于>0。
1. 如果a=0，输出NO。
2. 否则，只用a-1个1。此时d - (a - 1) 是偶数，输出YES。

注意到 d-a是奇数，等于 a/2+b-a是奇数（因为a=0），等于b是奇数。

总结：
1. a是奇数，输出NO
2. b 是奇数 且 a = 0，输出NO
3. 其他，输出YES

## 实现代码
```c++
#include<iostream>

int t, a, b;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> a >> b;
        if(a & 1) {
            std::cout << "NO\n";
            continue;
        }

        int x = a / 2 + b;
        if((x & 1) && a == 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}
```

## 要点
对a分类讨论