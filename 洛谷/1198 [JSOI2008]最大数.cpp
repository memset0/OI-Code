#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int read(void);
char readchar(void);
struct Node {
	int l, r, mid;
	int max;
} p[maxn * 8];
int n = 0, mxn = 0, m, v[maxn];
int t = 0, d, ans, tmmp = 0;
char x[maxn];
void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) / 2, p[u].max = 0;
	if (p[u].l == p[u].r) return ;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}
void insert(int u, int k, int c) {
	p[u].max = max(p[u].max, c);
	if (p[u].l == p[u].r) {
		if (k < p[u].l) while(1);
		else if (k > p[u].r) for (int i = 1; i <= 100; i++) puts("123");
		return;
	}
	if (p[u].l == p[u].r) return ;
//	if (k == p[u].l && k == p[u].r) return ;
	if (k <= p[u].mid) insert(u << 1, k, c);
	else insert(u << 1 | 1, k, c);
}
void lookup(int u, int l, int r) {
	if (l == p[u].l && r == p[u].r) {
		ans = max(ans, p[u].max);
		return ;
	}
	if (r <= p[u].mid) lookup(u << 1, l, r);
	else if (l > p[u].mid) lookup(u << 1 | 1, l, r);
	else {
		lookup(u << 1, l, p[u].mid);
		lookup(u << 1 | 1, p[u].mid + 1, r);
	}
}
int main() {
	cin >> m >> d; 
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> v[i];
		if (x[i] == 'A') mxn ++;
	}
//	cout << mxn << endl;
	build(1, 1, mxn);
	for (int i = 1; i <= m; i++) {
		if (x[i] == 'Q') {
			if (v[i] == 0 || n - v[i] + 1 < 1) {
				t = 0;
				printf("0\n");
			} else {
				ans = -2000000000;
				lookup(1, n - v[i] + 1, n);
				t = ans;
				printf("%d\n", ans);
			}
		} else {
			n++;
			if (n > m || n < 1) while (1);
			insert(1, n, (v[i] + t) % d);
		}
	}
	return 0;
}

int ret; char chr; bool mrk;
int read(void) {
	ret = 0, chr = getchar(), mrk = 0;
	while (!isdigit(chr) && chr != '-') chr = getchar();
	if (chr == '-') mrk = 1, chr = getchar();
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) return -ret; else return ret;
}
char readchar(void) {
	chr = getchar();
	while (!(islower(chr) || isupper(chr) || isdigit(chr))) chr = getchar();
	return chr;
}


//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 200010;
//int read(void);
//char readchar(void);
//int n = 0, mxn = 0, m, v[maxn], p[maxn * 16];
//int t = 0, d, ans;
//char x[maxn], tmp[10];
//void insert(int u, int i, int j, int k, int c) {
//	if (u == m * 4) {
//		printf("%d %d %d\n", u, i, j);
//	}
//	p[u] = max(p[u], c);
//	if (k == i && k == j) return;
//	int mid = (i + j) >> 1;
//	if (k <= mid) insert(u << 1, i, mid, k, c);
//	else insert(u << 1 | 1, mid + 1, j, k, c);
//}
//void lookup(int u, int i, int j, int l, int r) {
//	if (u == m * 4) {
//		printf("%d %d %d\n", u, i, j);
//	}
//	if (l == i && r == j) {
//		ans = max(ans, p[u]);
//		return ;
//	}
//	int mid = (i + j) >> 1;
//	if (r <= mid) lookup(u << 1, i, mid, l, r);
//	else if (l > mid) lookup(u << 1 | 1, mid + 1, j, l, r);
//	else {
//		lookup(u << 1, i, mid, l, mid);
//		lookup(u << 1 | 1, mid + 1, j, mid + 1, r);
//	}
//}
//int main() {
////	m = read(), d = read();
////	for (int i = 1; i <= m; i++) {
////		x[i] = readchar(), v[i] = read();
////		if (x[i] == 'A') mxn++;
////	}
//	cin >> m >> d; 
//	for (int i = 1; i <= m; i++) {
//		cin >> x[i] >> v[i];
//		if (x[i] == 'A') mxn ++;
//	}
//	for (int i = 1; i <= m; i++) {
//		if (x[i] == 'Q') {
//			if (v[i] == 0) {
//				t = 0;
//				printf("0\n");
//			} else {
//				ans = -2000000000;
//				lookup(1, 1, mxn, n - v[i] + 1, n);
//				t = ans;
//				printf("%d\n", ans);
//			}
//		} else {
//			n++;	
//			insert(1, 1, mxn, n, (v[i] + t) % d);
//		}
//	}
//	return 0;
//}

//int ret; char chr; bool mrk;
//int read(void) {
//	ret = 0, chr = getchar(), mrk = 0;
//	while (!isdigit(chr) && chr != '-') chr = getchar();
//	if (chr == '-') mrk = 1, chr = getchar();
//	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
//	if (mrk) return -ret; else return ret;
//}
//char readchar(void) {
//	chr = getchar();
//	while (!(islower(chr) || isupper(chr))) chr = getchar();
//	return chr;
//}




