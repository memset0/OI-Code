#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
long long x, y, ans = 0;
int a[maxn], b[maxn], c[maxn];
inline int cge(long long n, int a[]) {
	memset(a, 0, sizeof(a));
	for (long long t = n; t > 0; t /= 10) a[0]++;
	for (int i = a[0]; i > 0; i--) {
		a[i] = n % 10;
		n /= 10;
	}
}
inline int cmp(int a[], int b[]) {
	if (a[0] == b[0]) {
		for (int i = 1; i <= a[0]; i++)
			if (a[i] < b[i]) return -1;
			else if (a[i] > b[i]) return 1;
		return 0;
	}
	else if (a[0] < b[0]) return -1;
	else return 1;
}
inline int write(int a[]) {
	cout << a[0] << " : ";
	for (int i = 1; i <= a[0]; i++)
		cout << a[i];
	cout << endl;
}
int main() {
	cin >> x >> y;
	if (x > y) swap(x, y);
	cge(x, a), cge(y, b);
	for (int len = a[0]; len <= b[0]; len++) {
		//枚举长度 
		for (int i = 0; i < 10; i++) {
			//枚举有趣的数中重复的数 
			for (int j = 0; j < 10; j++) {
				//枚举有趣的数中的单独的数 
				if (i == j) continue; //去除全部数字都重复的情况
				for (int k = 1; k <= len; k++) {
					//枚举单独的数字的位置
					if (j == 0 && k == 1) continue;
					if (i == 0 && k != 1) break;
					for (int kk = 1; kk <= len; kk++) {
						//生成数
						if (kk == k) c[kk] = j;
						else c[kk] = i;
					}
					c[0] = len;
					if (cmp(a, c) == 1) continue; // a > c
					if (cmp(c, b) == 1) continue; // b < c
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0; 
}
