# A. [Special Characters](https://codeforces.com/problemset/problem/1948/A)
## 问题描述
给定整数n，要求构造一个由大写字母组成的字符串s，满足：

1. s恰好有n个字符：它的左右邻居恰好只有一个等于它自己。

## 问题思路
从较小的n开始，找规律：

当n=1，无解  
当n=2，输出AA即可  
当n=3，无解  
当n=4，AABAA  
当n=5，无解  
当n=6，AABAABAA  
...  

于是有个猜想：可以理解为任何s都由不断向后追加字母构成的，那么有2种可能：

1. 后追加的字母等于前一个字母：此时，如果前一个字母的贡献是1，那么后追加的字母会抢夺这个1，维持平衡。如果没有贡献，那么追加的字母会导致整个贡献+2
2. 后追加的字母不等于前一个字母：此时，如果前一个字母的贡献是1，那么不变，维持平衡。如果没有贡献，无影响，不变。

这个猜想在分类讨论中被证明，结论：n只能是偶数，奇数无解。

现在考虑如何快速+2，"BA"贡献是0，"BAA"贡献是2，"BAABAA"贡献是4，显然n个"BAA"的贡献是2*n，也就是输出n/2个"BAA"即可。

总结：
1. n为奇数，输出NO
2. n为偶数，输出n/2个"BAA"

## 实现代码
```c++
#include<iostream>

int t, n;
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        if(n & 1) {
            std::cout << "NO";
        } else {
            std::cout << "YES\n";
            for(int i = n / 2; i > 0; i--) {
                std::cout << "BAA";
            }
        }

        std::cout << "\n";
    }
    return 0;
}
```

## 要点
找规律

# C. [Arrow Path](https://codeforces.com/problemset/problem/1948/C)
## 问题描述
给定2行n列的网格，判断能否从 点(1,1)到点(2,n)。

网格由向左、向右的箭头组成，每次可以选择向上、下、左、右移动一步，然后根据箭头方向移动一步。

## 问题思路
想想看，什么时候无法到达呢？比如向右走，但是走到一个向左的接头上，然后会一直卡住——无法越过这个向左的单元格。

此时只能够向下或者向上走，此时分类讨论：

1. 其他方向也是向左：此时无解
2. 其他方向是向右，此时越过这一列

也就是说，我们应该模拟上述过程：用x，y表示当前的位置：

1. 判断当前是不是可以一步到达(2,n)，能够到达就输出yes
2. 否则，判断(x,y+1)的箭头方向，向右就y+2，进入下一轮循环。注意，即使这里走上不是最优的。
3. 否则，判断(x ^ 1 ^ 2, y)的箭头方向，向左就无解
4. 否则，坐标变为(x ^ 1 ^ 2, y + 1)，进入下一轮循环

## 实现代码
```c++
#include<iostream>

int t, n;
char mp[3][200001];

bool check() {
    int x = 1, y = 1;
    while(2 - x + n - y > 1) {
        char right_arrow = mp[x][y + 1];
        if(right_arrow == '>') {
            y += 2;
        } else {
            char top_arrow = mp[x ^ 1 ^ 2][y];
            if(top_arrow == '<') {
                return false;
            } else {
                x ^= 1 ^ 2;
                y = y + 1;
            }
        }
    }
    return true;
}

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= n; j++) {
                std::cin >> mp[i][j];
            }
        }

        if(check()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```

## 要点
这道题目：dp、搜索都可以做。我使用的是带贪心的模拟，使得的前提是证明：(x,y+1)的箭头方向向右时，向右走最优（因为此时还是有向上的选择的）。