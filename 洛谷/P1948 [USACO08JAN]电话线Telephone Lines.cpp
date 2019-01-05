//100分 二分答案 + 最短路
#include <bits/stdc++.h> 
using namespace std;
const int maxn = 1010;
const int maxm = 10010;
const int maxk = 1000000;
int n, m, k, x, y, z, u, v, a[maxn][maxn], p[maxn][maxn], length[maxn], pos[maxn], q[maxm * 10];
int spfa() {
	int l, r;
	memset(pos, 0, sizeof(pos));
	memset(length, -1, sizeof(length));
	l = r = q[1] = 1;
	length[1] = 0;
	while (l <= r) {
		u = q[l];
		pos[u] = 0;
		for (int i = 1; i <= n; i++) { 
			if (!pos[i] && p[u][i] != -1 && length[u] != -1 &&  (length[i] == -1 || length[u] + p[u][i] < length[i])) {
				length[i] = length[u] + p[u][i];
//				cout << length[i] << " ";
				q[++r] = i;
			}
		}
		l++;
	}
//	puts("length");
//	for (int i = 1; i <= n; i++)
//		cout << length[i] << " ";
//	puts("");
	if (length[n] == -1) return maxk + 1;
	return length[n];
}
int check(int mid) {
	memset(p, -1, sizeof(p));
//	cout << "mid = " << mid << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) p[i][j] = -1;
			else if (mid >= a[i][j]) p[i][j] = 0;
			else p[i][j] = 1;
//			printf("%3d", p[i][j]);
		}
//		puts("");
	}
	int x = spfa();
//	cout << x << endl;
	if (x <= k) return true;
	else return false;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
		a[y][x] = z;
	}
	int l = 0, r = maxk, mid;
	while (l + 3 <= r) {
		mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;	
	}
	for (int i = l; i <= r; i++)
		if (check(i)) {
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}

//70分 二分答案 + 宽搜 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1010;
//const int maxm = 10010;
//int n, m, k, x, y, z, maxx, a[maxn][maxn];
//bool found;
//struct Queue {
//	int k, p;
//	bool pos[maxn];
//} q[maxm * 20];
//bool check(int x) {
////	cout << x << endl;
//	int l, r;
//	l = r = 1;
//	q[1].p = q[1].pos[1] = 1, q[1].k = 0;
//	while (l <= r) {
////		cout << q[l].k << " ";
//		if (q[l].p == n) {
////			cout << endl;
//			return true;
//		}
//		for (int i = 1; i <= n; i++)
//			if (a[q[l].p][i] && !q[l].pos[i]) {
//				if (a[q[l].p][i] > x && q[l].k >= k) continue;
//				r++;
//				q[r] = q[l];
//				q[r].p = i;
//				q[r].pos[i] = 1;
//				if (a[q[l].p][i] > x) q[r].k++;
//			}
//		l++;
//	}
//	return false;
//}
////void DFS(int ui, int uk) {
////	if (ui == n) {
////		found = true;
////		return ;
////	}
////	for (int vi = 1; vi <= n; vi++) {
////		if (!found && a[ui][vi]) {
////			if (a[ui][vi] > maxx) {
////				if (uk < k) {
////					DFS(vi, uk + 1);
////				}
////			} else {
////				DFS(vi, uk);
////			}
////		}
////	}
////}
////bool check(int x) {
////	maxx = x;
////	found = false;
////	DFS(1, 0);
////}
//int main() {
//	cin >> n >> m >> k;
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d", &x, &y, &z);
//		a[x][y] = z;
//		a[y][x] = z;
//	}
//	int l = 0, r = 1000000, mid;
//	while (l + 3 < r) {
//		mid = (l + r) / 2;
//		if (check(mid)) r = mid;
//		else l = mid;
//	}
//	for (int i = l; i <= r; i++) 
//		if (check(i)) {
//			cout << i << endl;
//			return 0;
//		}
//	cout << -1 << endl;
//	return 0;
//}

////30分宽搜 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1010;
//const int maxm = 10010;
//struct Queue {
//	int point;
//	int way[maxn];
//	bool visited[maxn];
//} q[maxm * 2];
//int n, m, k, x, y, z, head, end, sum, ans = -1, p[maxn][maxn];
//bool my_sort(int a, int b) {
//	return a > b;
//}
//int main() {
////	freopen("phoneline.in", "r", stdin);
////	freopen("phoneline.out", "w", stdout);
//	cin >> n >> m >> k;
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d", &x, &y, &z);
//		p[x][y] = z;
//		p[y][x] = z;
//	} 
//	head = end = 1;
//	q[head].point = q[head].visited[1] = 1;
//	while (head <= end) {
//		if (end > 20010) {
//			cout << "-1\n";
//			return 0;
//		}
//		if (q[head].point == n) {
//			//到达终点
//			sort(q[head].way + 1, q[head].way + q[head].way[0] + 1);
//			if (q[head].way[q[head].way[0] - k] < ans || ans == -1) ans = q[head].way[q[head].way[0] - k];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (!q[head].visited[i] && p[q[head].point][i]) {
//				end++;
//				q[end] = q[head];
//				q[end].point = i;
//				q[end].way[++q[end].way[0]] = p[q[head].point][i];
//				q[end].visited[i] = 1;
//			}
//		}
//		head++;
//	}
//	cout << ans << endl;
//	return 0;
//}