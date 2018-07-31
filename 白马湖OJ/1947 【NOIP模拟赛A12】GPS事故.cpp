#include <bits/stdc++.h> 
#define nxt p[k][u][j].next
using namespace std;
const int maxn = 10010;
const int maxm = 50010;

struct str_map {
	int next, w;
} t;

vector < str_map > p[2][maxn];
vector < str_map > q[maxn];
vector < int > dis_from[maxn];
int n, m, in_q[maxn], dis[maxn];

void add_p(int a, int b, int pp1, int pp2) {
	p[0][a].push_back({b, pp1});
	p[1][a].push_back({b, pp2});
}
void add_q(int a, int b, int k) {
	q[a].push_back({b, k});
}

void spfa(int ctrl_num) {
	int k = ctrl_num, s = n, u;
	memset(dis, -1, sizeof(dis));
	queue < int > f; 
	f.push(s);
	while (f.size()) {
		u = f.front();
		f.pop();
		in_q[u] = false;
		cout << u;
		for (int j = 0; j < p[k][u].size(); j++) {
			if (in_q[nxt]) continue;
			if (dis[nxt] == -1 || dis[u] + p[k][u][j].w < dis[nxt]) {
				cout << 1;
				dis[nxt] = dis[u] + p[k][u][j].w;
				dis_from[nxt].clear();
				dis_from[nxt].push_back(u);
				in_q[nxt] = true;
				f.push(nxt);
			} else if (dis[u] + p[k][u][j].w == dis[nxt]) {
				dis_from[nxt].push_back(u);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int a, b, pp1, pp2;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &a, &b, &pp1, &pp2);
		add_p(a, b, pp1, pp2);
		add_p(b, a, pp1, pp2);
	}
	spfa(0);
	spfa(1);
	return 0;
}

