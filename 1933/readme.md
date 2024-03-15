# D. [Turtle Tenacity: Continual Mods](https://codeforces.com/problemset/problem/1933/D)
## 问题描述
给定长度n的整数数组a，重新排列a得到数组b。
现在问，是否存在b，满足：

1. b[1] % b[2] % b[3] % ... % b[n] != 0

存在输出yes，否则输出no

## 问题思路
说到排序，最简单的就是按照顺序从小到大排列，我们会发现最后一个数非常重要。

感觉题目描述有问题，看了测试案例后，发现说的是取模的过程中不能出现0，而不是n个数取模的结果不能为0。

既然如此只能看第一个数：也就是最小值。

如果最小值唯一，显然满足要求。

否则，需要在后面找到一个i，使得b[i] % b[1] != 0，这样就可以得到新的唯一最小值。如果找不到，那么输出no。

## 实现代码
```c++
#include<iostream>
#include<algorithm>

int t, n, a[100001];
int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a, a + n);
        if(a[0] != a[1]) {
            std::cout << "YES\n";
            continue;
        }

        bool has = false;
        for(int i = 1; i < n; i++) {
            if(a[i] % a[0] != 0) {
                has = true;
                break;
            }
        }

        if(has) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```

## 要点
a % b = c, c = 0 （当a = b）  
a % b = c, 0 <= c < b （当a > b时）  
a % b = c, 0 < c <= b （当a < b时）  