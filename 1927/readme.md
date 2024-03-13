# B. [Sasha and the Drawing](https://codeforces.com/problemset/problem/1929/B)

## 问题描述
给定长度n的整数数组a，要求构造字符串s，满足：
1. a[i] 等于 s[i] == s[j] (j < i) 的个数。

## 问题思路
尝试倒着求s[i]，发现如果a[i]=x，那么一定存在a[j]=x-1，直到a[k]=0。
那么a[j]的j的顺序会不会造成影响呢？显然是不会的，就算是有多个值等于x-1，我们只需要选择最后一个作为a[j]即可。

实现思路变为：
定义数组b来表示a-z的字符，对于当前a[i]，判断能否找到索引j满足a[i]=b[j]。  

1. 如果能找到，输出 char (j+'a')，并b[j]--。  
2. 找不到，令索引j=b.size()，输出char(j+'a')，并b[j]=a[i]-1。

## 实现代码
```c++
#include<iostream>
#include<vector>
int t, n, a[200001];
char ans[200001];

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> b;

        for(int i = n - 1; i >= 0; i--) {
            int j = 0;
            while(j < b.size() && b[j] != a[i]) j++;
            if(j == b.size()) {
                b.push_back(a[i]-1);
            } else {
                b[j]--;
            }
            ans[i] = (char) ( j + 'a');
        }

        for(int i = 0; i < n; i++) {
            std::cout << ans[i];
        }
        std::cout << "\n";
    }
    return 0;
}
```

## 要点
模拟