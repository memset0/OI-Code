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

const int maxn = 35, maxm = 8010, mod = 1e6 + 3;

int n, m, u, v, tu, tv, ln, rn, cnt;
int f[1 << 24], g[1 << 24];

int tot = 2, hed[maxn], nxt[maxm], to[maxm];

void dfs1(int s, int t) {
	if (~f[s]) return;
	cnt++;
	f[s] = 0;
	for (int u = 1; u <= ln; u++) {
		int tu = 1 << (u - 1);
		if ((s & tu) == 0) {
			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
				int tv = 1 << (v - 1);
				if ((s & tv) == 0) {
					if (v <= ln) {
						dfs(s | tu | tv);
						f[s] = (f[s] + f[s | tu | tv]) % mod;
						// printf("%d <- %d\n", s, s | tu | tv);
					} else {
						dfs()
					}
				}
			}
			break;
		}
	}
}

void dfs2(int s) {
	if (~g[s]) return;
	g[s] = 0;
	for (int u = 25; u <= rn; u++) {
		int tu = 1 << (u - 1);
		if ((s & tu) == 0) {
			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
				int tv = 1 << (v - 1);
				if ((s & tv) == 0 && tv > 24) {
					dfs(s | tu | tv);
					g[s] = (g[s] + g[s | tu | tv]) % mod;
					// printf("%d <- %d\n", s, s | tu | tv);
				}
			}
			break;
		}
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	memset(f, -1, sizeof(f));

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		if (u > v) swap(u, v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		// nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	

	// ln = 2, rn = 2;
	// f[(1 << ln) - 1] = 1;
	// g[(1 << rn) - 1] = 1;
	// dfs2(0);
	// dfs1(0);

	// if (n <= 24) {
	// 	ln = n;
	// 	f[(1 << ln) - 1] = 1;
	// 	dfs1(0);
	// 	printf("%d\n", f[0]);
	// } else {
	// 	ln = 24, rn = n - 24;
	// 	f[(1 << ln) - 1] = 1;
	// 	g[(1 << rn) - 1] = 1;
	// 	dfs1(0), dfs2(0);
	// 	for (int i = 1; i < (1 << ln); i++) {
	// 		for (int j = 1; j < (1 << rn); j++) {
	// 			dfs3(i, j);
	// 		}
	// 	}
	// 	return 0;
	// }

	// for (int i = 0; i < (1 << ln); i++)
	// 	printf("%d %d\n", i, f[i]);

	return 0;
}

// // ==============================
// //  author: memset0
// //  website: https://memset0.cn
// // ==============================
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// int read() {
//     int x = 0; bool m = 0; char c = getchar();
//     while (!isdigit(c) && c != '-') c = getchar();
//     if (c == '-') m = 1, c = getchar();
//     while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
//     if (m) return -x; else return x;
// }

// const int maxn = 35, maxm = 8010, mod = 1e6 + 3;

// int n, m, u, v, tu, tv, ln, rn, cnt;
// int f[1 << 24], g[1 << 24];

// int tot = 2, hed[maxn], nxt[maxm], to[maxm];

// void dfs1(int s, int t) {
// 	if (~f[s]) return;
// 	cnt++;
// 	f[s] = 0;
// 	for (int u = 1; u <= ln; u++) {
// 		int tu = 1 << (u - 1);
// 		if ((s & tu) == 0) {
// 			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
// 				int tv = 1 << (v - 1);
// 				if ((s & tv) == 0) {
// 					if (v <= ln) {
// 						dfs(s | tu | tv);
// 						f[s] = (f[s] + f[s | tu | tv]) % mod;
// 						// printf("%d <- %d\n", s, s | tu | tv);
// 					} else {
// 						dfs()
// 					}
// 				}
// 			}
// 			break;
// 		}
// 	}
// }

// void dfs2(int s) {
// 	if (~g[s]) return;
// 	g[s] = 0;
// 	for (int u = 25; u <= rn; u++) {
// 		int tu = 1 << (u - 1);
// 		if ((s & tu) == 0) {
// 			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
// 				int tv = 1 << (v - 1);
// 				if ((s & tv) == 0 && tv > 24) {
// 					dfs(s | tu | tv);
// 					g[s] = (g[s] + g[s | tu | tv]) % mod;
// 					// printf("%d <- %d\n", s, s | tu | tv);
// 				}
// 			}
// 			break;
// 		}
// 	}
// }

// int main() {
// 	// freopen("INPUT", "r", stdin);
// 	memset(f, -1, sizeof(f));

// 	n = read(), m = read();
// 	for (int i = 1; i <= m; i++) {
// 		u = read(), v = read();
// 		if (u > v) swap(u, v);
// 		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
// 		// nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
// 	}
	

// 	// ln = 2, rn = 2;
// 	// f[(1 << ln) - 1] = 1;
// 	// g[(1 << rn) - 1] = 1;
// 	// dfs2(0);
// 	// dfs1(0);

// 	// if (n <= 24) {
// 	// 	ln = n;
// 	// 	f[(1 << ln) - 1] = 1;
// 	// 	dfs1(0);
// 	// 	printf("%d\n", f[0]);
// 	// } else {
// 	// 	ln = 24, rn = n - 24;
// 	// 	f[(1 << ln) - 1] = 1;
// 	// 	g[(1 << rn) - 1] = 1;
// 	// 	dfs1(0), dfs2(0);
// 	// 	for (int i = 1; i < (1 << ln); i++) {
// 	// 		for (int j = 1; j < (1 << rn); j++) {
// 	// 			dfs3(i, j);
// 	// 		}
// 	// 	}
// 	// 	return 0;
// 	// }

// 	// for (int i = 0; i < (1 << ln); i++)
// 	// 	printf("%d %d\n", i, f[i]);

// 	return 0;
// }



// // // ==============================
// // //  author: memset0
// // //  website: https://memset0.cn
// // // ==============================
// // #include <bits/stdc++.h>
// // #define ll long long
// // using namespace std;

// // int read() {
// //     int x = 0; bool m = 0; char c = getchar();
// //     while (!isdigit(c) && c != '-') c = getchar();
// //     if (c == '-') m = 1, c = getchar();
// //     while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
// //     if (m) return -x; else return x;
// // }

// // const int maxn = 35, maxm = 8010, mod = 1e6 + 3;

// // int n, m, u, v, tu, tv, ln, rn;
// // int f[1 << 24];

// // int tot = 2, hed[maxn], nxt[maxm], to[maxm];

// // int main() {
// // 	// freopen("INPUT", "r", stdin);
	
// // 	n = read(), m = read();
// // 	for (int i = 1; i <= m; i++) {
// // 		u = read(), v = read();
// // 		if (u > v) swap(u, v);
// // 		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
// // 		// nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
// // 	}
	
// // 	if (n > 24) {
// // 		puts("0");
// // 		return 0;
// // 	}
// // 	ln = min(24, n);
// // 	f[0] = 1;
// // 	// for (int t = 0; t <= ((1 << ln) - 1); t++) {
// // 	// 	for (int u = 1; u <= ln; u++)
// // 	// 		if (!(t & (1 << (u - 1))))
// // 	// 			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
// // 	// 				if (!(t & (1 << (v - 1)))) {
// // 	// 					f[t | (1 << (u - 1)) | (1 << (v - 1))] += f[t];
// // 	// 					printf("%d(%d) -> %d(%d) : %d %d\n", t, f[t], t | (1 << (u - 1)) | (1 << (v - 1)), f[t | (1 << (u - 1)) | (1 << (v - 1))], u, v);
// // 	// 				}
// // 	// }
// // 	// for (int u = 1; u <= ln; u++)
// // 	// 		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
// // 	// 			for (int t = 0; t <= ((1 << ln) - 1); t++) {
// // 	// 				tu = 1 << (u - 1), tv = 1 << (v - 1);
// // 	// 				if ((t & tu) == 0 && (t & tv) == 0)
// // 	// 					f[t | tu | tv] = (f[t] + f[t | tu | tv]) % mod;
// // 	// 			}
// // 	cout << f[(1 << ln) - 1] << endl;

// // 	return 0;
// // }
