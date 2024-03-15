# A. [Entertainment in MAC](https://codeforces.com/problemset/problem/1935/B)

## 问题描述
给定偶数n和字符串s，可以执行两种操作：
1. 将当前s反转。
2. 向当前s后面加上反转后的s。

现在求执行n次后，最小字母顺序的s

## 问题思路
为了让字母顺序最小，显然应该尽可能减少s的长度：也就是多的使用操作1。

于是发现，如果s的字母顺序小于等于反转后的s，那么直接输出s即可：因为n是偶数，所以执行n/2次操作1就可以得到原s。
否则，需要将s反转n-1次，最后一次执行操作2，得到反转s+s。

## 实现代码
```c++
#include<iostream>
#include<algorithm>

int t, n;
std::string s;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> s;
        std::string a = s;
        std::reverse(a.begin(), a.end());

        if(s <= a) {
            std::cout << s << "\n";
        } else {
            std::cout << a + s << "\n";
        }
    }
    return 0;
}
```
## 要点
贪心

# B. [Informatics in MAC](https://codeforces.com/problemset/problem/1935/B)
## 问题描述
给定长度n的数组a，要求将a分为k段连续的子数组，且所有子数组的MEX值相等

## 问题思路
先求整个数组a的MEX，记作x。

显然需要所有子数组的MEX等于x。

简单的证明：如果存在不等于x，记作y。显然y < x，并且一个会有一个子数组的MEX为y，且包含y+1，这与假设矛盾。

因为要求k大于1，所以可以先从前往后遍历，找到索引i使得 [0, i]构成的子数组的MEX=x。然后再判断[i+1, n-1]构成的子数组的MEX是否等于x，如果是那么输出答案即可，否则没有解。

求MEX可以借助数组，使得可以线性求出结果。

## 实现代码
```c++
#include<iostream>

int t, n, a[100001];
bool has[100001];

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        // 求x: 表示a的MEX
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int x = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            has[a[i]] = true;
            while(has[x]) x++;
        }

        // 求idx：[0, idx]的MEX等于x
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int y = 0, idx = -1;
        for(int i = 0; i < n; i++) {
            has[a[i]] = true;
            while(has[y]) y++;
            if(y == x) {
                idx = i;
                break;
            }
        }

        // 求z：表示[idx+1, n]的MEX
        for(int i = 0; i <= n; i++) {
            has[i] = false;
        }
        int z = 0;
        for(int i = idx + 1; i < n; i++) {
            has[a[i]] = true;
            while(has[z]) z++;
        }

        if(z == x) {
            std::cout << "2\n";
            std::cout << 1 << " " << idx + 1 << "\n";
            std::cout << idx + 2 << " " << n << "\n";
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}
```

## 要点
意识到：答案若存在，则所有a的子数组的MEX等于a的MEX