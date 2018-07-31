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
	while (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z')) c = getchar();
	return c;
}
const int maxn = 257;
int n, m, cnt, fir, ans[maxn], deg[maxn], g[maxn][maxn];
char u, v;
void DFS(int u) {
	for (int i = 1; i < maxn; i++)
		if (g[u][i]) {
			g[u][i] = g[i][u] = 1;
			DFS(i);
		}
	ans[m--] = u;
}
int main() {
	freopen("INPUT", "r", stdin);
	n = m = read();
	for (int i = 1; i <= m; i++) {
		u = readc(), v = readc();
//		cout << u << " " << v << endl;
		g[u][v] = g[v][u] = 1;
		deg[u]++, deg[v]++;
		cout << u << " " << deg[u] << endl;
	}
	for (int i = 1; i < maxn; i++)
		cout << deg[i] << endl;
	for (int i = 1; i < maxn; i++)
		if (deg[i] & 1) {
			cnt++;
			cout << i << endl; 
			if (!fir) fir = i;
		}
	if (cnt && cnt != 2) {
		printf("No Solution\n");
		return 0;
	}
	if (!fir)
		for (int i = 1; i < maxn; i++)
			if (deg[i]) {
				fir = i;
				break;
			}
	DFS(1);
	for (int i = 1; i <= n; i++)
		printf("%c", ans[i]);
	putchar('\n');
	return 0;
}





//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//int read() {
//	int x = 0; bool m = 0; char c = getchar();
//	while (!isdigit(c) && c != '-') c = getchar();
//	if (c == '-') m = 1, c = getchar();
//	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
//	if (m) return -x; else return x;
//}
//char readc() {
//	char c = getchar();
//	while (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z')) c = getchar();
//	return c;
//}
//const int maxn = 60, maxm = 3010;
//int n, m, u, v, cnt, fir, ans_n, min_n, min_c, flag, pos = -1, id[256], ch[maxn], f[maxn], deg[maxn], ans[maxn], hed[maxn], nxt[maxm], to[maxm], used[maxm];
//char cu, cv;
//void link(int &u, int &v) {
//	nxt[++pos] = hed[u];
//	hed[u] = pos;
//	deg[u]++;
//	to[pos] = v;
//}
//void DFS(int u) {
//	for (int j = hed[u]; j; j = nxt[j])
//		if (!used[j]) {
//			used[j] = used[j ^ 1] = 1;
//			DFS(to[j]);
//		}
//	cout << u << ' ' << ans_n << endl; 
//	ans[ans_n--] = u;
//}
//int main() {
//	m = read();
//	for (int i = 1; i <= m; i++) {
//		cu = readc(), cv = readc();
//		if (id[cu]) u = id[cu];
//		else u = id[cu] = ++n, ch[u] = cu;
//		if (id[cv]) v = id[cv];
//		else v = id[cv] = ++n, ch[v] = cv;
//		link(u, v);
//		link(v, u);
//	}
//	ans_n = n;
//	for (int i = 1; i <= n; i++)
//		if (deg[i] & 1) {
//			cnt++;
//			if (!fir) fir = i;
//		}
//	if (cnt && cnt != 2) {
//		printf("No Solution\n");
//		return 0;
//	}
//	if (!fir)
//		for (int i = 1; i <= n; i++)
//			if (deg[i]) {
//				fir = i;
//				break;
//			}
//	DFS(1);
////	for (int i = 0; i < 256; i++)
////		if (id[i]) {
////			printf("%c %d\n", i, id[i]);
////		}
//	min_n, min_c = 256;
//	for (int i = 1; i <= n; i++)
//		if (ch[ans[i]] < min_c) {
//			min_c = ch[ans[i]];
//			min_n = i;
//		}
//	ans[0] = ans[n], ans[n + 1] = ans[1];
//	if (ans[ans_n + 1] < ans[ans_n - 1]) flag = 1;
//	if (flag) {
//		for (int i = min_n; i <= n; i++)
//			putchar(ch[ans[i]]);
//		for (int i = 1; i <= min_n; i++)
//			putchar(ch[ans[i]]);
//	} else {
//		for (int i = min_n; i >= 1; i--)
//			putchar(ch[ans[i]]);
//		for (int i = n; i >= min_n; i--)
//			putchar(ch[ans[i]]);
//	}
//	putchar('\n');
//	return 0;
//}
