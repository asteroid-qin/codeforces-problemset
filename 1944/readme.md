# B. [Permutation Printing](https://codeforces.com/problemset/problem/1930/B)
## 问题描述
给定长度2*n数组c，其中1到n恰好出现2次。给定整数k，要求构造数组l和r，满足：

1. l是c的1到n的子集，l的长度是2 * k
2. r是c的n+1到2 * n的子集，r的长度是2 * k
3. l的所有元素的异或=r的所有元素的异或

输出l和r

## 问题思路
乍一看没有解决部分，解决问题的关键在c的构成：1到n恰好出现2次。

不妨令c的1到n的前半部分称为数组lc，后半部分称为数组rc。在lc中，如果出现元素1，可以对它分类讨论：

1. 出现1次。lc中出现一次，那么rc中必然也出现过一次。
2. 出现2次。我们可以选择2个，使得异或和为0

因此，我们可以先计算l：

1. 先计算lc中1到n所有元素出现的次数得到数组a
2. 循环1到n，如果a[i]==2并且l的长度+2不超过2 * k，那么把这两个元素放入l中
3. 再循环一次a，如果a[i]==1并且l的长度+1不超过2 * k,那么把当前元素放入（经历2，3要么一个都不放，要么只放一个）

同样的，可以计算r。最后输出l和r即可。

## 实现代码
```c++
#include<iostream>

int t, n, k;
int a[50001], b[50001];
int ans_a[50001], ans_b[50001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            a[i] = b[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            int x; std::cin >> x;
            a[x]++;
        }
        for(int i = 0; i < n; i++) {
            int x; std::cin >> x;
            b[x]++;
        }

        int len_a = 0, len_b = 0;

        for(int i = 1; i <= n; i++) {
            if(a[i] == 2 && len_a + 2 <= 2 * k) {
                ans_a[++len_a] = i;
                ans_a[++len_a] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(a[i] == 1 && len_a + 1 <= 2 * k) {
                ans_a[++len_a] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(b[i] == 2 && len_b + 2 <= 2 * k) {
                ans_b[++len_b] = i;
                ans_b[++len_b] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(b[i] == 1 && len_b + 1 <= 2 * k) {
                ans_b[++len_b] = i;
            }
        }

        for(int i = 1; i <= len_a; i++) {
            std::cout << ans_a[i] << " ";
        }
        std::cout << "\n";

        for(int i = 1; i <= len_b; i++) {
            std::cout << ans_b[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

## 要点
读题