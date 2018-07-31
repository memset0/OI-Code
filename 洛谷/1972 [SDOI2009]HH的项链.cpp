//Õý½â 

//Äª¶Ó 

//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//
//int read() {
//    int x = 0; bool m = 0; char c = getchar();
//    while (!isdigit(c) && c != '-') c = getchar();
//    if (c == '-') m = 1, c = getchar();
//    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
//    if (m) return -x; else return x;
//}
//
//const int maxn = 50010, maxm = 200010;
//int n, sqn, m, tl, tr, now, ans[maxm], a[maxn], bel[maxm], cnt[1000001];
//struct Query{
//	int l, r, i;
//} b[maxm];
//inline bool cmp(Query &a, Query &b) { return bel[a.l] ^ bel[b.l] ? a.l < b.l : bel[a.l] & 1 ? a.r < b.r : a.r > b.r; }
//int main() {
//	n = read(), sqn = sqrt(n);
//	for (int i = 1; i <= n; i++)
//		bel[i] = i / sqn;
//	for (int i = 1; i <= n; i++)
//		a[i] = read();
//	m = read();
//	for (int i = 1; i <= m; i++)
//		b[i].l = read(), b[i].r = read(), b[i].i = i;
//	sort(b + 1, b + m + 1, cmp);
//	tl = 1, tr = 0;
//	for (int i = 1; i <= m; i++) {
////		printf("%d %d %d %d\n", i, b[i].i, b[i].l, b[i].r);
//		while (b[i].l < tl) now += !cnt[a[--tl]]++;;
//		while (b[i].l > tl) now -= !--cnt[a[tl++]];;
//		while (b[i].r > tr) now += !cnt[a[++tr]]++;;
//		while (b[i].r < tr) now -= !--cnt[a[tr--]];;
//		ans[b[i].i] = now;
//	}	
//	for (int i = 1; i <= m; i++)
//		printf("%d\n", ans[i]);
//	return 0;
//}
