# B. [StORage room](https://codeforces.com/problemset/problem/1903/B)

## 问题描述

给定n * n的矩阵a，要求找到一个长度为n的数组b，使得：

1. a[i] [j] = b[i] | b[j] （如果i 不等于 j）



## 问题思路

尝试让b[i] = (1 << 30) - 1，然后移除影响答案的位。



最后判断得到的b[i]是否满足要求即可。



举个例子：b[1]。

首先，b[1]初始值是 (1 << 30) - 1，

b[1]会与b[2]、b[3]、b[4]、...、b[n] 与操作从而得到 n -1不同的值。



定义 2 <= k <= n:

如果a[1] [k] 的某位是0，那么b[1]的这位也同样得是0。为了快速把0取掉，我们可以 & 操作。

如果a[1] [k] 的某位是1，那么b[1]的这位也同样得是1。因为b[1] 和 b[k] 中至少有1个这位是1，不妨默认都是1。



## 实现代码

```c++
#include<iostream>

int t, n, a[1000][1000], b[1000];

void slv() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		b[i] = (1 << 30) - 1;
	}
	
	for(int i = 0; i < n; i++) 
	for(int j = 0; j < n; j++)
	{
		std::cin >> a[i][j];
		if(i != j) {
			b[i] &= a[i][j];
			b[j] &= a[i][j];
		}
	}
	
	bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && (b[i] | b[j]) != a[i][j]){
                ok = false;
            }
        }
    }
    
    if(!ok){
        std::cout<<"NO\n";
        return;
    }
    
    std::cout<<"YES\n";
    for(int i = 0; i < n; i++){
        std::cout << b[i] << " ";
    }
    
    std::cout << "\n";
}
int main() {
	std::cin >> t;
	while(t--) {
		slv();
	}
	return 0;
} 
```



## 要点

位运算
