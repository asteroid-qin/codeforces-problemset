# A. [Li Hua and Maze](https://codeforces.com/problemset/problem/1797/A)

## 问题描述：

在n*m大小的迷宫，给两个点的坐标。一开始迷宫都是空着的，求至少放几个障碍物使得两个点不互通。



## 问题思路：

首先关注给的2个坐标的其中1个，对它的位置进行分类讨论发现有3种：

1. 卡在角落。这种情况的坐标有4种可能，并且只需要2个障碍物就可以封死。

2. 贴近墙上。这种情况有很多种，此时需要3个障碍物才能封死。
3. 四周无墙。最后一种情况，需要4个障碍物才能封死。

对上述总结，发现封死一个点，我们只需要做3种分类讨论即可，可以写一个公共方法。问题的答案就是分别封死两个点的最小值。



## 实现代码：

```c++
#include<iostream>

int t, m, n;

int get(int x, int y) {
    // 这里的思想是：我们只关注坐标在不在角落至于哪个角落并不重要，所以可以把4个角落的坐标映射为第1个角落的位置，这样判断代码变得更简洁
	int p = x == m ? 1 : x;
	int q = y == n ? 1 : y;
	if(p == 1 && q == 1) {
		return 2;
	} 
	
	if(p == 1 || q == 1) {
		return 3;
	}
	return 4;
}

void slv() {
	int x1, x2, y1, y2;
	std::cin >> m >> n >> x1 >> x2 >> y1 >> y2;
	std::cout << std::min(get(x1, x2), get(y1, y2)) << "\n";
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点：

抓住重点，分类讨论



# B. [Li Hua and Pattern](https://codeforces.com/problemset/problem/1797/B)

## 问题描述：

在n*n大小的0-1矩阵里，可以选一个坐标将0变成1或者1变成0。现在问能不能执行恰好k次使得，操作后的0-1矩阵旋转180°后不变。



## 问题思路：

翻转180°也就是对每个坐标满足：。可以先把至少值cnt全部求出来，然后分类讨论：

1. cnt > k。最小都不满足，肯定打印NO。
2. cnt<=k，n为偶数。此时如果k-cnt为奇数那么会多出1次操作，也就是得输出NO，否则YES。
3. cnt<=k，n为奇数。此时如果k-cnt为奇数那么会多出偶数次操作，也就是可以恰好k次完成，输出YES；否则，多出1次操作，因为n为奇数，所有存在一个点n/2+1和n/2+1翻转后不变的，因此同样输出YES



## 实现代码：

```c++
#include<iostream>

int t, k, n, a[1001][1001], b[1001][1001];
 
void slv() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) 
	for(int j = 1; j <= n; j++)
	std::cin >> a[i][j];
	
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[n - i + 1][n - j + 1] != a[i][j]) cnt++;
		}
	}
	cnt /= 2; // 这里因为算了2遍所以得/2
	 
	if(k < cnt || (n % 2 == 0  && (k - cnt) % 2 == 1) ) std::cout << "NO\n";
	else {
		std::cout << "YES\n";
	}
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```



## 要点：

分类讨论