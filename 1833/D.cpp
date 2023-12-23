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

// ��[1, ans_r] �ҵ�ans_l������ans_r, ansr-1 ... ansl, 1, 2, 3 .. �߼���� 
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
	
	// �ҵ����ֵ������
	int max_idx = getIdx(1, n);
	
	if(max_idx == 1) {
		int sec_max_idx = getIdx(2, n);
		ans_r = sec_max_idx - 1;
	} else {
		ans_r = max_idx - 1;
	}
	
	// ����һ�ֿ��ܣ� ans_r+1 = n����ʱans_r���Ե���n
	if(ans_r + 1 == n) {
		ans_r = n;
	}
	
	// �ҵ�[1, ans_r] ��ans_l
	ans_l = getAnsL(ans_r);
	
	// ������ 
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
// 4
// 3 1 2 4
