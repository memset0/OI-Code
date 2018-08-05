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


const int maxn = 10000010, inf = 1e9 + 10;
int n, m, len;
char ch, s[maxn];
short a[maxn], b[maxn], c[maxn];

void walk(char *s, short *a, int &n) {
	len = strlen(s), n = 0;
	for (int i = 0; i < len; i++) {
		ch = s[i];
		if (ch == '1') {
			a[++n] = 0;
		} else if (ch == '2') {
			a[++n] = 1;
		} else if (ch == 'U') {
			n--;
		} else if (ch == 'L') {
			for (int i = n; i > 0; i--)
				if (!a[i]) a[i] = 1;
				else {
					a[i] = 0;
					break;
				}
		} else if (ch == 'R') {
			for (int i = n; i > 0; i--)
				if (a[i]) a[i] = 0;
				else {
					a[i] = 1;
					break;
				}
		}
	}
}

void print(string name, short *arr, int length) {
	cout << name << " ";
	for (int i = 1; i <= length; i++)
		printf("%d ", arr[i]);
	puts("");
}

bool grt(short *a, short *b) {
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}
	return 0;
}
void swp(short *a, short *b) {
	short tmp;
	for (int i = 1; i <= n; i++)
		tmp = a[i], a[i] = b[i], b[i] = tmp;
}

int pass(short *a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret = ret << 1 | a[i];
	return ret;
}

vector < int > g[maxn];
int inq[maxn], dis[maxn];

inline void add_edge(int u, int v) {
//	printf("ADDEDGE %d %d\n", u, v);
	g[u].push_back(v);
	g[v].push_back(u);
}

void build(int dep) {
	int l = 1, r = 1;
	for (int i = 1; i <= dep + 1; i++) {
		for (int j = l; j <= r; j++)
			add_edge(j >> 1, j);
		for (int j = l + 1; j <= r; j++)
			add_edge(j - 1, j);
		l = l << 1, r = (l << 1) - 1;
	}
}

int spfa(int s, int e) {
	memset(dis, 63, sizeof(dis));
	queue < int > q;
	dis[s] = 0;
	q.push(s), inq[s] = 1;
	int u;
	while (q.size()) {
		u = q.front(), q.pop(), inq[u] = 0;
		for (vector < int > ::iterator it = g[u].begin(); it != g[u].end(); it++)
			if (dis[*it] > dis[u] + 1) {
				dis[*it] = dis[u] + 1;
				if (!inq[*it]) {
					inq[*it] = 1;
					q.push(*it);
				}
			}
	}
//	cout << s << " " << e << endl;
//	for (int i = 1; i <= e; i++)
//		cout << dis[i] << " ";
//	puts("");
	return dis[e];
}

int main() {
	
//	freopen("board.in", "r", stdin);
//	freopen("board.out", "w", stdout);
//	freopen("data.txt", "r", stdin);
	
	scanf("%s", s), walk(s, a, n);
	scanf("%s", s), walk(s, b, m);
	
//	print("A", a, n);
//	print("B", b, m);
	
	int S = pass(a, n);
	int E = pass(b, m);
	build(max(n, m));

	printf("%d\n", spfa(S, E));

	return 0;
}
