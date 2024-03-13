# A. [Sasha and the Beautiful Array](https://codeforces.com/problemset/problem/1929/A)

## 问题描述
给定长度n的整数数组a，定义sum为ai-a{i-1}的和，现在可以重新排列a，求sum的最大值。

## 问题思路
因为 sum = a2 - a1 + a3 - a2 + ... + an - a{n-1} = an - a1 

所以想让sum最大只需要让an最大，a1最小即可。

因此，求a的最大值与最小值，并输出他们的差即可。

## 实现代码
```c++
#include<iostream>

int t, n, a;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        int p = -1, q = 2e9;
        for(int i = 0; i < n; i++) {
            std::cin >> a;
            p = std::max(p, a);
            q = std::min(q, a);
        }

        std::cout << p -  q << "\n";
    }

    return 0;
}
```

## 要点
化简

# B. [Sasha and the Drawing](https://codeforces.com/problemset/problem/1929/B)

## 问题描述
给定n * n 的矩阵 a和整数k。一开始a的初始值为0，定义p为a的对角线上的和不为0的对角线数。 现在要求找出整数x，满足：
  
1. x是将a中部分单元格+1的次数。
2. a中部分单元格+1后，p >= k。
3. x最小

## 问题思路
尝试x从1开始加入矩阵a，问题是什么情况最优呢？

案例三给出一种思路：

1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 

x在1-n时，我们把它放在第一列上，每次最多增加2。
此时第一列的最上方和最下方作对角线，他们会在最后一列上吃掉2块单元格：第一个和最后一个。

也就是说x在1-2n-2的时候都是每次最大增加2，当x取2n-2时达到最大值4n-4，而实际上p最大可以是4n-2。

因此，需要对k分类讨论：
1. 当k在4n-4的范围内，输出k/2向上取整。
2. 否则，输出2n-2+k-4n+4也就是k-2n+2。

## 实现代码
```c++
#include<iostream>

int t, n, k;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> k;

        if(4 * n - 4 >= k) {
            std::cout << (k + 1) / 2 << "\n";
        } else {
            std::cout << k - 2 * n + 2 << "\n";
        }
    }
    return 0;
}
```

## 要点
分类讨论