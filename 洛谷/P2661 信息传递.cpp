#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 200010;
int n, u, v, cnt, pos, ans, __cnt, dis[maxn], id[maxn], nxt[maxn];
int main() {
	n = read(), ans = n;
	for (int i = 1; i <= n; i++)
		nxt[i] = read();
	for (int i = 1; i <= n; i++)
		if (!id[i]) {
			pos++, u = i;
			while (!id[u]) { 
				id[u] = pos;
				u = nxt[u];
			}
			if (id[u] == pos) {
				v = nxt[u], cnt = 0;
				while (v != u) {
					v = nxt[v];
					cnt++;
				}
				ans = min(ans, cnt);
			}
		}
	cout << ++ans << endl;
	return 0;
}









//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 200010;
//int n, u, ans, uans, nxt[maxn], vis[maxn], cut[maxn], cnt[maxn];
//int main() {
//	scanf("%d", &n);
//	ans = n + 1;
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &nxt[i]), cnt[nxt[i]]++;
//	//删除入度为0的点（避免死循环等） 	
//	for (int i = 1; i <= n; i++) {
//		for (u = i; !cnt[u] && !cut[u]; u = nxt[u]) {
//			cut[u] = 1;
//			cnt[nxt[u]]--;
//		}
//	}
//	//暴力DFS求最小环 
//	for (int i = 1; i <= n; i++)
//		if (!cut[i]) {
//			uans = 1;
//			for (u = nxt[i]; u != i; u = nxt[u]){
//				uans++;
//			}
//			ans = min(ans, uans);
//		}
////	for (int i = 1; i <= n; i++)
////		if (!vis[i] && !cut[i]) {
////			vis[i] = 1;
////			uans = 1;
////			for (u = nxt[i]; u != i; u = nxt[u]) {
//////				printf("%d ", u);
////				vis[u] = 1;
////				uans ++;
////			}
////			ans = min(ans, uans);
////		}
//	printf("%d\n", ans);
//	return 0;
//}
//
//
//
//////读优 + 一般模拟 80分TLE
////#include <bits/stdc++.h> 
////#define isNum(x) ('0'<=x&&x<='9')
////using namespace std;
////const int maxn = 200010;
////int n, ans, a[maxn], val[maxn], pos[maxn];
////char get; int ret;
////int read() {
////    get = getchar(), ret = 0;
////    while (!isNum(get)) get = getchar();
////    while (isNum(get)) {
////        ret = ret * 10 + get - '0';
////        get = getchar();
////    }
////    return ret;
////}
////int main() {
////    memset(val, 0, sizeof(val));
////    n = read();
////    for (int i = 1; i <= n; i++)
////        a[i] = read();
////    ans = n + 1;
////    int i, j, k;
////    for (i = 1; i <= n; i++) {
////        if (val[i]) continue;
////        memset(pos, 0, sizeof(pos));
////        k = pos[i] = 1;
////        for (j = a[i]; pos[j] != -1; j = a[j]) {
////            k++;
////            if (pos[j]) {
////                val[j] = k - pos[j];
////                pos[j] = -1;
////            } else {
////                pos[j] = k;
////            }
////        }
////    }
////    for (int i = 1; i <= n; i++)
////        if (val[i] != 0 && val[i] < ans) ans = val[i];
////    cout << ans << endl;
////    return 0;
////}
