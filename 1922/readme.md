# 问题描述
给定长度为n的字符串a、b、c，定义字符串s匹配t：
1. 如果s[i]是小写字母，s[i]必须等于t[i]。
2. 如果s[i]是大写字母，小写s[i]必须不等于t[i]。

现在要求判断是否存在字符串s，满足：s匹配a、b且s不匹配c。

# 问题思路
因为前后互不影响，因此可以只考虑单个字符，并以此解决整个字符串问题。

显然选择一个不等于a[i]、b[i]、c[i]的大写字母是可以任意匹配的（因此只要存在一个索引满足题目要求就足够了），问题转化为对s[i]分类讨论：

1. 如果s[i]是小写，那么s[i]必须等于a[i]、等于b[i]，且不等于c[i]。
2. 如果s[i]是大写，那么s[i]必须等于c[i]，且不等于a[i]、不等于b[i]。

只要**存在**i满足上面条件，那么输出YES，否则输出NO。

条件1转化为：a[i]=b[i] 且 a[i] != c[i]。

条件2转化为：a[i] != c[i] 且 c[i] != b[i]

# 实现代码
```c++
#include <iostream>

int t, n;
std::string a, b, c;
int main () {
    std::cin >> t;
    while(t--) {
        std::cin >> n >> a >> b >> c;
        bool has = false;
        for(int i = 0; i < n; i++) {
            if( (a[i] == b[i] && a[i] != c[i]) ||
                    (a[i] != c[i] && b[i] != c[i]) ) {
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

# 要点
把问题从字符串转化为：存在对位字符满足条件后，再对s[i]分类讨论。