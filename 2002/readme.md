# A. [Distanced Coloring](https://codeforces.com/problemset/problem/2002/A)
## 问题描述
给定长n宽m的2维数组a，给定整数k。现在要求，给a[i][j]赋值并满足：

1. 如果a[i][j]=a[p][q]，那么max(|i-p|, |j-q|) >= k。

现在求a[i][j]不同元素的个数的最小值是多少。

## 问题思路
不妨从a[1][1]开始，从第一行开始，从值1开始排放。

显然位置 a[1][1]、a[1][1+k]、a[1][1+2*k]、... 的值可以都是1。

继续使用值1，尝试放置，发现只能从1+k行开始：
a[1+k][1]、a[1+k][1+k]、a[1+k][1+2*k]、... 的值可以都是1。

到这里，我们明白了：(1, 1) 到 (k, k) 元素的个数便是答案。也就是直接输出 k*k 即可。

但是考虑到n、m与k的关系不确定，因此答案应该是：

min(k, n) * min(k, m)



## 实现代码
```c++
#include<iostream>

int t, n, m, k;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m >> k;
        std::cout << std::min(n, k) * std::min(m, k) << "\n";
    }
    return 0;
}
```
## 要点
大胆找规律