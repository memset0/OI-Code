#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 2010;
int n, k, frm, al, bl, af, bf;
ll l, r, l_, r_, ans, f1[20], f2[20];
double final_ans, a[maxn], f[maxn][maxn];

void get(ll x, int &l, int &f) {
	ll t = x;
	l = f = 0;
	while (t) {
		f = t % 10;
		l++;
		t /= 10;
	}
}

int main() {
//	freopen("chance.in", "r", stdin);
//	freopen("chance.out", "w", stdout);
	scanf("%d%d\n", &n, &k);
	
	f1[1] = 1, f2[1] = 2;
	for (int i = 2; i <= 19; i++)
		f1[i] = f1[i - 1] * 10, f2[i] = f2[i - 1] * 10; 
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &l, &r);
//		printf("%lld")
		l_ = l, r_ = r;
		ans = 0;
		get(l, al, af);
		get(r, bl, bf);
//		printf("%d %d %d %d\n", al, af, bl, bf);
		while (al < bl) {
			if (af == 1)
				ans += f2[al] - l;
//			printf(">>> %d %lld %lld\n", al, f2[al], l);
			l = f1[al + 1];
			al++, af = 1;
		}
		if (al == bl)
			if (af == 1 && bf == 1)
				ans += r - l + 1;
			else if (af == 1)
				ans += f2[al] - l;
		a[i] = ans / (double) (r_ - l_ + 1);
//		cout << ans << endl;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = f[i - 1][j] * (1 - a[i]) + f[i - 1][j - 1] * a[i];
//	for (int i = 1; i <= n; i++)
//		printf("%.7lf\n", a[i]);
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++)
//			printf("%.7lf ", f[i][j]);
//		puts("");
//	}
	if (n * k % 100 == 0) frm = n * k / 100;
	else frm = n * k / 100 + 1;
	for (int i = frm; i <= n; i++) {
		final_ans += f[n][i];
//		cout << i << " " << f[n][i] << endl;
	}
	printf("%.7lf\n", final_ans);
	return 0;
}

