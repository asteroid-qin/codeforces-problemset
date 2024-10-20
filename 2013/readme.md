# A. [Zhan's Blender](https://codeforces.com/problemset/problem/2013/A)
## 问题描述
给定整数 n、x、y。求 n / min(x, y) 向上取整的值。

## 问题思路
模拟即可

## 实现代码
```c++
#include<iostream>

int t, n, x, y;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> x >> y;
        int a = std::min(x, y);

        std::cout << (n + a - 1) / a << "\n";
    }
    return 0;
}
```
## 要点
审题

# B. [Battle for Survive](https://codeforces.com/problemset/problem/2013/B)
## 问题描述
给定长度为整数n的数组a，做n-1次如下操作：

1. 选择下标i和j，满足：1 <= i < j <= n
2. 将数组a中的元素a[i]抹去，同时 a[j] = a[j] - a[i]

现在问：最后剩下1个的最大值是多少？

## 问题思路
明确一点：这个最大值一定是 a[n] 加减 a[i] （i < n）的结果。

注意到，a[n]必然会减去a[n-1]，于是最大值一定是 a[n] - a[n-1] 加减 a[i] （i < n-1）的结果。

注意到，我们可以让 a[n-1] - a[1] - a[2] - ... - a[n-2]，于是最大值显然是：

数组a的和减去2倍的a[n-1]

## 实现代码
```c++
#include<iostream>

int t, n, a;

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; i++) {
            std::cin >> a;
            sum += a;
            if(i == n - 1) {
                sum -= 2 * a;
            }
        }

        std::cout << sum << "\n";
    }
    return 0;
}
```
## 要点
注意到结果的 a[n]必然减去a[n-1]