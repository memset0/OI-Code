#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 2010;
int n, sum, u[3], ans[6][3]; 
struct Node {
	int a, p;	
} a[maxn];
bool bkt[210][210][210];
bool cmp(Node a, Node b) {
	if (a.p == b.p) return a.a < b.a;
	return a.p < b.p;
}
void print() {
	for (int t = 0; t < 6; t++)
		cout << "=== " << ans[t][0] << " " << ans[t][1] << " " << ans[t][2] << endl;
}
void append(int *u) {
	for (int k = 0; k < 6; k++) {
		if (ans[k][0] > u[0] && ans[k][1] > u[1] && ans[k][2] > u[2])
			return ;
		if (ans[k][0] <= u[0] && ans[k][1] <= u[1] && ans[k][2] <= u[2]) {
			ans[k][0] = u[0];
			ans[k][1] = u[1];
			ans[k][2] = u[2];
			return ;
		}
	}
//	printf("error!\n");
}
int main() {
//	freopen("youginzi.in", "r", stdin);
//	freopen("youginzi.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].a = read(), a[i].p = read();
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//		cout << a[i].a << " " << a[i].p << endl;
	for (int i = 1; i <= n; i++) {
		memset(u, 0, sizeof(u));
		for (int j = i; j <= n; j++) 
			if ((a[i].p << 1) > a[j].p) {
				u[a[j].a]++;
			} else break;
		append(u);
//		cout << u[0] << " " << u[1] << " " << u[2] << endl;
//		print();
	}
	for (int t = 0; t < 6; t++) {
		for (int i = 0; i <= ans[t][0]; i++)
			for (int j = 0; j <= ans[t][1]; j++)
				for (int k = 0; k <= ans[t][2]; k++) {
					if (!bkt[i][j][k]) {
						bkt[i][j][k] = 1;
						sum++;
					}
//					cout << i << " " << j << " " << k << endl;
				}
	}
	printf("%d\n", sum);
	return 0;
}
