# A. [Brick Wall](https://codeforces.com/problemset/problem/1918/A)
## 问题描述
给定n行m列的矩阵，要求用1行k列的砖铺完（k>1）。

现在要让水平方向的砖尽可能最大，并求水平方向的砖-竖直方向的砖数量。

## 问题思路
很简单的贪心，可以让水平方向的砖的长度最小=2，然后最大可能得使用它，剩下的由一个竖直方向的砖搞定。

如果m是偶数，那么每列可以由m/2个砖构成，因此答案是 m/2*n  
如果m是奇数，那么前m-2列可以由长度2个砖构成，最后3列使用长度3的，因此答案是 m/2*n。

总结，输出 m/2*n
## 实现代码
```c++
#include<iostream>

int t, n, m;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m;
        std::cout << m / 2 * n << "\n";
    }
    return 0;
}
```

## 要点
贪心

# B. [Minimize Inversions](https://codeforces.com/problemset/problem/1918/B)
## 问题描述
给定长度n的两个全排列：a, b.可以执行以下操作任意次：
1. 选择两个索引i，j，交换a[i]和a[j]，交换b[i]和b[j]

现在需要输出a和b的某种排列，满足a和b的逆序对的和最小

## 问题思路
咋一看没有好的办法，仔细想想：怎么快速让逆序对最小？答案是排序。
于是：不妨将数组a排序，再输出此时的b？

证明的话没有思路，但是值得一试。

实现的代码很简单：创建一个node，它的x放a[i]，y放i值。对node的a[i]字段排序，得到的i值便是b真正的顺序。

此时的答案便是：
1. 输出1到n（这是a）
2. 输出b[x[i].y]（这是b）

下面的实现代码为了偷懒，使用拉姆达表达式，思想是一样的。
## 实现代码
```c++
#include<iostream>
#include<algorithm>

int t, n, a[200001], b[200001], c[200001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
            c[i] = i;
        }
        for(int i = 1; i <= n; i++) std::cin >> b[i];

        std::sort(c+1, c+n+1, [&](const int x, const int y) {
            return a[x] < a[y];
        });

        for(int i = 1; i <= n; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        for(int i = 1; i <= n; i++) {
            std::cout << b[c[i]] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
```

## 要点
题感