#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
const int maxm = 500010;
int n, m, s, l = 0, h[maxn], front[maxn];
struct Edge {
	int val, nxt, end;
} edge[maxm];
queue <int> q;
int main() {
	memset(h, -1, sizeof(h));
	memset(front, -1, sizeof(front));
	int x, y, z;
	cin >> n >> m >> s;
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		edge[++l].val = z;
		edge[l].end = y;
		edge[l].val = z;
		if (front[x] == -1) edge[l].nxt = -1;
		else edge[l].nxt = front[x];
		front[x] = l;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", front[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		if (front[i] != -1)
//			for (int j = front[i]; j != -1; j = edge[j].nxt)
//				cout << i << " " << edge[j].end <<  " " << edge[j].val << endl;
//	puts("");
	h[s] = 0;
	q.push(s);
	int u, v;
	while (!q.empty()) {
		u = q.front(), q.pop();
		if (front[u] == -1) continue;
		for (int j = front[u]; j != -1; j = edge[j].nxt) {
//			cout << j << " " << edge[j].nxt << " " << edge[j].val << " " << edge[j].end << endl;
			if (h[edge[j].end] > h[u] + edge[j].val || h[edge[j].end] == -1) {
				h[edge[j].end] = h[u] + edge[j].val;
				q.push(edge[j].end);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (h[i] == -1)	printf("2147483647 ");
		else printf("%d ", h[i]);
	puts("");
	return 0;
}