// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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

char readc() {
	char c = getchar();
	while (c != 'M' && c != 'A') c = getchar();
	return c;
}

const int maxn = 1000010;

int n, m, l, r, x, sqn, opt, ans, cnt;
typedef int r_n[maxn];
r_n a, b, bln;
typedef int r_sqn[1010];
r_sqn siz, tag, fst;

int query(int i, int x) {
	return siz[i] - (lower_bound(b + fst[i], b + fst[i + 1], x - tag[i]) - b - fst[i]);
}

int main() {
	
	n = read(), m = read();
	sqn = sqrt(n);
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = read();
	for (int i = 1; i <= n; i++) {
		bln[i] = (i - 1) / sqn + 1;
		siz[bln[i]]++;
		if (!fst[bln[i]])
			fst[bln[i]] = i;
	}
	fst[bln[n] + 1] = n + 1;
	for (int i = 1; i <= bln[n]; i++) {
		sort(b + fst[i], b + fst[i + 1]);
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", b[i]);
//	puts("");
	
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'A') {
			l = read(), r = read(), x = read(), ans = 0;
			if (bln[l] ^ bln[r]) {
				for (int i = bln[l] + 1; i <= bln[r] - 1; i++) ans += query(i, x);
				for (int i = l; i < fst[bln[l] + 1]; i++) if (a[i] + tag[bln[i]]>= x) ans++;
				for (int i = fst[bln[r]]; i <= r; i++) if (a[i] + tag[bln[i]] >= x) ans++;
			} else for (int i = l; i <= r; i++) if (a[i] + tag[bln[i]] >= x) ans++;
			printf("%d\n", ans);
		} else {
			l = read(), r = read(), x = read();
			if (bln[l] ^ bln[r]) {
				for (int i = bln[l] + 1; i <= bln[r] - 1; i++) tag[i] += x;
				for (int i = l; i < fst[bln[l] + 1]; i++) a[i] += x;
				for (int i = fst[bln[l]]; i < fst[bln[l] + 1]; i++) b[i] = a[i];
				sort(b + fst[bln[l]], b + fst[bln[l] + 1]);
				for (int i = fst[bln[r]]; i <= r; i++) a[i] += x;
				for (int i = fst[bln[r]]; i < fst[bln[r] + 1]; i++)	b[i] = a[i];
				sort(b + fst[bln[r]], b + fst[bln[r] + 1]);
			} else {
				for (int i = l; i <= r; i++) a[i] += x;
				for (int i = fst[bln[l]]; i < fst[bln[l] + 1]; i++) b[i] = a[i];
				sort(b + fst[bln[l]], b + fst[bln[l] + 1]);
			}
		}
	}

	return 0;
}

