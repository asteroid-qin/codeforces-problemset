# B. [Paranoid String](https://codeforces.com/problemset/problem/1694/B)

## 问题描述

给定长度m的01字符串t，如果t能执行m-1次操作，那么t是**好的**：

1. 选择t 等于的 01 的子串，然后替换为1
2. 选择t 等于的 10 的子串，然后替换为0



现在给了长度n的字符串s，求s的所有是**好的**子串的数量



## 问题思路

正常想并不简单，需要把题目的操作变形，得到更容易理解结论。

注意到01变1，10变成0，其实就是：**右边的字符把左边不相等的字符消除**。



那么我们可以循环s，对于当前s[i]，不妨令s[i] = 1。

最简单的，如果前面[0, i-1] 都是0，那么我们可以都消除掉。所以以i作为右端点的子字符串的贡献是i+1



但是如果前面出现了1个1呢？

如果s[i-1] = 0，那么因为0可以消除左边所有的1，只剩下0。而s[i]=1又可以消除左边所有的0，所以贡献依旧是i+1。

否则，因为**右边的字符只能把左边不相等的字符消除**，s[i]无法消除s[i-1]，所以以i作为右端点包含s[i-1]无论如何消除，最终长度都会>=2，因此贡献是1。



总结：

初始ans=0，循环s：

如果s[i] == s[i-1]，那么ans+1

否则，ans+=i+1



## 实现代码

```c++
#include<iostream>

int t, n;
std::string s;

int main() {
	std::cin >> t;
	while(t--) {
		std::cin >> n >> s;
		long long ans = 1;
		for(int i = 1;  i < n; i++) {
			if(s[i] == s[i-1]) ans++;
			else ans += i + 1;
		}
		std::cout << ans << "\n";
	}
	return 0;
} 
```



## 要点

右边的字符可以把左边所有不相等的字符消除掉，只剩下自己