# A. [Red Versus Blue](https://codeforces.com/problemset/problem/1659/A)

## 问题描述

给a个0和b个1，排列它们，使得连续出现的最少。a严格大于b。



## 问题思路

既然a严格大于b，那么可以把1隔开，然后在每一块放a。



显然，如果a=b+1，那么连续出现的次数的最大值为1。

如果a=b+1+1，那么只能是2.

如果a=b+1+2，依旧是2

...

如果a=b+1+b+1，依旧是2.

如果a=b+1+b+1+1，最大是3.



总结：

最大是(a+b)/(b+1)。



至于输出结果：

可以先让每个0都是最大值，再*(b + 1)得到值c。显然c-a个地方需要-1处理即可。



## 实现代码

```c++
#include<iostream>

int t, r, b, n;
int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> r >> b;
		int x = (r + b) / (b + 1);
		int cnt = x * (b + 1) - r;
		
		for(int i = 1; i <= n; ) {
			int cur_x = x;
			if(cnt > 0) {
				cur_x--;
				cnt--;
			}		
			for(int j = cur_x;j > 0; j--) {
				std::cout << "R";
			}			
			i += cur_x;
				
			if(b > 0) {
				std::cout << "B";
				b--;
				i++;
			}
		}
		std::cout << "\n";
	}
	return 0;
} 
```





## 要点

把0一个个分开，然后想办法插入1。