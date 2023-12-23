# D. [Flipper](https://codeforces.com/problemset/problem/1833/D)

## 问题描述

给一个长度n的1-n的全排列，必须执行一次操作，选择两个下标l,r，将原数组分为3段，中间翻转，左右位置交换，得到新的排列。问题要求：给定全排列，输出一次操作后的逻辑最大的新排列。



## 问题思路

要满足逻辑最大，首先应该找到数组的最大值，尝试让最大值放在首位。

如果最大值的索引是1，那么如论如何都无法把它放在首位，退而求其次，找次大值的索引。

我们已经拿到最大值或者次大值的索引，显然r的值是索引值-1，并且不会大于索引值，但是r会不会等于呢？有一种情况可能会，那就是索引值是n，也就是这个最大值或者次大值位于数组的末尾，这种情况我们可以让r等于n。

已经确认r的值，问题变成了：

在[1, r] 找到 l，满足a[r]，a[r-1]，...， a[l]，1，2，3，... 逻辑最大。

这个问题可以在线性内解决。在一开始，可以让l等于r=n，我们尝试扩充[l,r]的范围：

// an a1 a2 a3 ...		l=n
// an an-1 a1 a2 ...	l=n-1
// an an-1 an-2 a1     l=n-2

根据这个我们可以找到规律：如果a[l-1]可以取到且大于a[1]，那么l--，否则循环停止。

至此，l和r的值都已经确认，问题解决。



## 代码实现

```c++
#include<iostream>

int t, n, a[2001]; 

int getIdx(int l, int r) {
	int res = l, mx = a[l];
	while(l <= r) {
		if(a[l] > mx) {
			mx = a[l];
			res = l;
		}
		l++;
	}
	return res;
}

// 在[1, ans_r] 找到ans_l，满足ans_r, ansr-1 ... ansl, 1, 2, 3 .. 逻辑最大 
// an a1 a2 a3 ...
// an an-1 a1 a2 ...
// an an-1 an-2 a1
int getAnsL(int ans_r) {
	int res = ans_r;
	int l = 1; 
	while(res - 1 >= 1 && a[res - 1] >= a[1]) {
		res--;
		l++;
	}
	return res;
}



void slv() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	if(n == 1) {
		std::cout << a[1] << "\n";
		return;
	}

	int ans_l, ans_r;
	
	// 找到最大值的索引
	int max_idx = getIdx(1, n);
	
	if(max_idx == 1) {
		int sec_max_idx = getIdx(2, n);
		ans_r = sec_max_idx - 1;
	} else {
		ans_r = max_idx - 1;
	}
	
	// 还有一种可能： ans_r+1 = n，此时ans_r可以等于n
	if(ans_r + 1 == n) {
		ans_r = n;
	}
	
	// 找到[1, ans_r] 的ans_l
	ans_l = getAnsL(ans_r);
	
	// 输出结果 
	for(int i = ans_r + 1; i <= n; i++) {
		std::cout << a[i] << " ";
	}	
	
	for(int i = ans_r; i >= ans_l; i--) {
		std::cout << a[i] << " ";
	}
	
	for(int i = 1; i <= ans_l - 1; i++) {
		std::cout << a[i] << " ";
	} 
	std::cout << "\n"; 
}

int main() {
	std::cin >> t;
	while(t--) slv();
	return 0;
} 
```





## 要点

分类讨论