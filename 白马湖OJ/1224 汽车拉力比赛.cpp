#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, a[maxn][maxn], b[maxn][maxn], vis[maxn][maxn];
int cnt, vx, vy, sx, sy, tags, q[maxn * maxn];
bool find();
void toFill(int i, int j, int x) {
//	cout << i << " "  << j << " " << x << endl;
	for (int t = 0; t < 4; t++) {
		vx = i + mov[t][0];
		vy = j + mov[t][1];
		if (vx < 1 || vy < 1 || vx > n || vy > m) continue;
		if (vis[vx][vy]) continue;
		if (abs(a[i][j] - a[vx][vy]) <= x) {
			vx = i + mov[t][0];
			vy = j + mov[t][1];
			vis[vx][vy] = 1;
			if (b[vx][vy]) cnt++;
			toFill(vx, vy, x);
		}
	}
}
bool check(int x) {
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	vis[sx][sy] = 1, cnt++;
	toFill(sx, sy, x);
	if (cnt == tags) return true;
	return false;
}
//bool check(int x) {
//	bool tt = check_(x);
//	cout << x << ": ";
//	cout << tt << endl;
//	return tt;
//}
int main() {
//	freopen("ccski.in", "r+", stdin);
//	freopen("ccski.out", "w+", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int maxx = a[1][1], minn = a[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > maxx) maxx = a[i][j];
			if (a[i][j] < minn) minn = a[i][j];
		}
	tags = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
			if (b[i][j]) {
				tags++;
				sx = i, sy = j;
			}
		}
	int L = 0, R = maxx - minn, Mid, ans;
	while (L + 3 < R) {
		Mid = (L + R) / 2;
		if (check(Mid)) R = Mid;
		else L = Mid;
	}
	for (Mid = L; Mid <= R; Mid++)
		if (check(Mid)) {
			ans = Mid;
			break;
		}
//	printf("L=%d R=%d\n", L, R);
	printf("%d", ans);
	return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 510;
//const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//int n, m, a[maxn][maxn], b[maxn][maxn], vis[maxn][maxn];
//int cnt, vx, vy, sx, sy, tags, q[maxn * maxn];
//bool find();
//void toFill(int i, int j, int x) {
////	cout << i << " "  << j << " " << x << endl;
//	for (int t = 0; t < 4; t++) {
//		vx = i + mov[t][0];
//		vy = j + mov[t][1];
//		if (vx < 1 || vy < 1 || vx > n || vy > m || vis[vx][vy]) continue;
//		if (abs(a[i][j] - a[vx][vy]) <= x) {
//			vx = i + mov[t][0];
//			vy = j + mov[t][1];
//			vis[vx][vy] = 1;
//			if (b[vx][vy]) cnt++;
//			toFill(vx, vy, x);
//		}
//	}
//}
//bool check(int x) {
//	memset(vis, 0, sizeof(vis));
//	cnt = 0;
//	vis[sx][sy] = 1, cnt++;
//	toFill(sx, sy, x);
//	if (cnt == tags) return true;
//	return false;
//}
////bool check(int x) {
////	bool tt = check_(x);
////	cout << x << ": ";
////	cout << tt << endl;
////	return tt;
////}
//int main() {
//	freopen("ccski.in", "r+", stdin);
//	freopen("ccski.out", "w+", stdout);
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			scanf("%d", &a[i][j]);
//	int maxx = a[1][1], minn = a[1][1];
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			if (a[i][j] > maxx) maxx = a[i][j];
//			if (a[i][j] < minn) minn = a[i][j];
//		}
//	tags = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			scanf("%d", &b[i][j]);
//			if (b[i][j]) {
//				tags++;
//				sx = i, sy = j;
//			}
//		}
//	int L = 0, R = maxx - minn, Mid, ans;
//	while (L + 3 < R) {
//		Mid = (L + R) / 2;
//		if (check(Mid)) R = Mid;
//		else L = Mid;
//	}
//	for (Mid = L; Mid <= R; Mid++)
//		if (check(Mid)) {
//			ans = Mid;
//			break;
//		}
////	printf("L=%d R=%d\n", L, R);
//	printf("%d", ans);
//	return 0;
//}
