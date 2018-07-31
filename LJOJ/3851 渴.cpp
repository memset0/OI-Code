#include <bits/stdc++.h> 
//#define DEBUG 1
#define ll long long
using namespace std;
int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 200010;
int n, m, L, R, S, E, u, tx, ty;
int tmp[maxn], id[maxn], far[maxn], dep[maxn], nxt[maxn], fah[maxn], dpt[maxn], dis[maxn], q[maxn];
vector < int > G[maxn];

int find_max_location(int *a, int length) {
	int maxn = a[1], maxi = 1;
	for (int i = 2; i <= length; i++)
		if (a[i] > maxn) {
			maxn = a[i];
			maxi = i; 
		}
	return maxi;
}

void DFS_dpt(int u, int depth, int father) {
	dpt[u] = depth;
	fah[u] = father;
	for (vector < int > ::iterator it = G[u].begin(); it != G[u].end(); ++it)
		if (!dpt[*it])
			DFS_dpt(*it, depth + 1, u);
}

void DFS_dep(int u, int depth, int grand) {
	dep[u] = depth;
	far[id[grand]] = max(far[id[grand]], depth);
	id[u] = id[grand];
	for (vector < int > ::iterator it = G[u].begin(); it != G[u].end(); ++it)
		if (!dep[*it] && (*it) != fah[u])
			DFS_dep(*it, depth + 1, u);
}

class tree {
	private: 
		struct Node {
			int l, r, mid, max;
		} p[maxn << 2];
	public:
		void build(int u, int l, int r) {
			p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
			if (l == r) {
				p[u].max = tmp[l];
				return ;
			}
			build(u << 1, l, p[u].mid);
			build(u << 1 | 1, p[u].mid + 1, r);
			p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
		}
		int query(int u, int l, int r) {
			if (l > r) return 0;
			if (p[u].l == l && p[u].r == r) {
				return p[u].max;
			}
			if (r <= p[u].mid) return query(u << 1, l, r);
			else if (l > p[u].mid) return query(u << 1 | 1, l, r);
			else return max(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
		}
} t1, t2;

int main() {

//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
#ifdef DEBUG
	freopen("INPUT", "r", stdin);
	freopen("OUTPUT", "w", stdout);
//	freopen("thirst.in", "r", stdin);
//	freopen("thirst.out", "w", stdout);
#endif
	
	n = read();
	for (int i = 1; i < n; i++) {
		tx = read(), ty = read();
		G[tx].push_back(ty);
		G[ty].push_back(tx);
	}
	
	bool flag = 1;
	for (int i = 1; i < n; i++)
		if (G[i].size() > 2) {
			flag = 0;
			break;
		}
#ifdef DEBUG
	cout << "SIZ ";
	for (int i = 1; i <= n; i++)
		cout << G[i].size() << " ";
	cout << endl;
#endif
	
	if (flag) {
#ifdef DEBUG
		cout << "flag" << endl;
#endif
		for (int i = 1; i <= n; i++)
			if (G[i].size() == 1) {
				if (!S) S = i;
				else E = i;
			}
#ifdef DEBUG
		cout << S << " " << E << endl;
#endif 
		int cnt = 0;
		id[S] = ++cnt, u = G[S][0], nxt[S] = G[S][0];
		while (u != E) {
			for (int i = 0; i < 2; i++)
				if (!nxt[G[u][i]])
					nxt[u] = G[u][i];
#ifdef DEBUG
			cout << "u = " << u << " nxt[u] = " << nxt[u] << endl;
#endif
			id[u] = ++cnt;
			u = nxt[u];
		}
		id[E] = ++cnt;
#ifdef DEBUG
		cout << "NXT ";
		for (int i = 1; i <= n; i++)
			cout << nxt[i] << " ";
		cout << endl;
		cout << " ID ";
		for (int i = 1; i <= n; i++)
			cout << id[i] << " ";
		cout << endl;
#endif
		m = read();
		for (int i = 1; i <= m; i++) {
			tx = read(), ty = read();
			if (id[tx] > id[ty]) swap(tx, ty);
			int ans = 0, mid = (id[ty] + id[tx]) >> 1;
			ans = max(ans, id[tx] - id[S]);
			ans = max(ans, id[E] - id[ty]);
			ans = max(ans, min(id[ty] - mid, mid - id[tx]));
#ifdef DEBUG
			printf("%d %d %d %d %d ", id[ty] - mid, mid - id[tx], id[tx], mid, id[ty]);
#endif
			printf("%d\n", ans);
		}
		return 0;
	}
	
	memset(dis, 0, sizeof(dis));
	L = R = 1, q[1] = 1, dis[1] = 1;
	while (L <= R) {
		u = q[L++];
		for (vector < int > ::iterator it = G[u].begin(); it != G[u].end(); ++it)
			if (!dis[*it]) {
				dis[*it] = dis[u] + 1;
				q[++R] = *it;
			}
	}
	//找树的直径
	S = find_max_location(dis, n);
	memset(dis, 0, sizeof(dis));
	L = R = 1, q[1] = S, dis[S] = 1;
	while (L <= R) {
		u = q[L++];
		for (vector < int > ::iterator it = G[u].begin(); it != G[u].end(); ++it)
			if (!dis[*it]) {
				dis[*it] = dis[u] + 1;
				q[++R] = *it;
			}
	}
	E = find_max_location(dis, n);
#ifdef DEBUG
	cout << "S = " << S << endl << "E = " << E << endl;
#endif
	//以S为根节点建树
	DFS_dpt(S, 1, -1);
#ifdef DEBUG 
	cout << "FAH ";
	for (int i = 1; i <= n; i++)
		cout << fah[i] << " ";
	cout << endl;
	cout << "DPT ";
	for (int i = 1; i <= n; i++)
		cout << dpt[i] << " ";
	cout << endl;
#endif
	//找到树的直径
	nxt[E] = -1;
	u = E;
	while (fah[u] != -1) {
		nxt[fah[u]] = u;
		u = fah[u];
	}
#ifdef DEBUG
	cout << "NXT ";
	for (int i = 1; i <= n; i++)
		cout << nxt[i] << " ";
	cout << endl;
#endif
	//计算直径上每个点的id[i]
	u = S;
	id[u] = 1;
	while (nxt[u] != -1) {
		id[nxt[u]] = id[u] + 1;
		u = nxt[u];
	}
	//计算每个点到树的直径的深度dep[i] & 每个点的id[i]
	u = S;
	while (nxt[u] != -1) {
		for (vector < int > ::iterator it = G[u].begin(); it != G[u].end(); it++)
			if ((*it) != fah[u] && (*it) != nxt[u])
				DFS_dep(*it, 1, u);
		u = nxt[u];
	}
#ifdef DEBUG
	cout << "DEP "; 
	for (int i = 1; i <= n; i++)
		cout << dep[i] << " ";
	cout << endl;
	cout << "FAR ";
	for (int i = 1; i <= n; i++)
		cout << far[i] << " ";
	cout << endl;
	cout << " ID ";
	for (int i = 1; i <= n; i++)
		cout << id[i] << " ";
	cout << endl;
#endif
	//线段树维护最大值 t1 => id[i] + dep[i] t2 => id[i] - dep[i]
	memset(tmp, -63, sizeof(tmp));
	for (int i = 1; i <= id[E]; i++)
		tmp[i] = far[i] + i;
//	for (int i = 1; i <= n; i++)
//		tmp[id[i]] = max(tmp[id[i]], id[i] + dep[i]);
	t1.build(1, 1, id[E]);
#ifdef DEBUG
	cout << "TMP ";
	for (int i = 1; i <= id[E]; i++)
		cout << tmp[i] << " ";
	cout << endl;
	cout << " T1 ";
	for (int i = 1; i <= id[E]; i++)
		cout << t1.query(1, i, i) << " ";
	cout << endl;
#endif 
	memset(tmp, -63, sizeof(tmp));
	for (int i = 1; i <= n; i++)
		tmp[i] = far[i] - i;
//	for (int i = 1; i <= n; i++)
//		tmp[id[i]] = max(tmp[id[i]], dep[i] - id[i]);
	t2.build(1, 1, id[E]);
#ifdef DEBUG
	cout << "TMP ";
	for (int i = 1; i <= id[E]; i++)
		cout << tmp[i] << " ";
	cout << endl;
	cout << " T2 "; 
	for (int i = 1; i <= id[E]; i++)
		cout << t2.query(1, i, i) << " ";
	cout << endl;
#endif

	//开始乱搞
	m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		int ans = 0;
		if (id[x] > id[y]) swap(x, y);
#ifdef DEBUG
		printf("=== %d === (%d, %d)\n", i, x, y);
#endif 
//		if (id[x] == id[y]) ans = max(ans, min(dep[x], dep[y]) + max(id[E] - id[x], id[x] - 1)); 
//		else ans = max(ans, max(dep[x] + id[x] - 1, dep[y] + id[E] - id[y]));
		ans = max(ans, min(dep[x] + id[x] - 1, dep[y] + id[y] - 1));
		ans = max(ans, min(dep[x] + id[E] - id[x], dep[y] + id[E] - id[y]));
		int distance = dep[x] + dep[y] + id[y] - id[x], mid = id[x] + (distance >> 1) - dep[x];
		if (mid > id[y]) {
//			printf("Error!\nid[x]=%d mid=%d id[y]=%d\n", id[x], mid, id[y]);
			mid = id[y];
		}
		if (id[x] + 1 <= mid - 1) ans = max(ans, t1.query(1, id[x] + 1, mid - 1) + dep[x] - id[x]);
		if (mid + 1 <= id[y] - 1) ans = max(ans, t2.query(1, mid + 1, id[y] - 1) + dep[y] + id[y]);
		if (mid != id[x] && mid != id[y]) ans = max(ans, min(dep[x] + far[mid] + mid - id[x], dep[y] + far[mid] + id[y] - mid));
#ifdef DEBUG
		printf("dep[x] + id[x] - 1 = %d\n", dep[x] + id[x] - 1);
		printf("dep[y] + id[E] - id[y] = %d\n", dep[y] + id[E] - id[y]);
		printf("distance = %d mid = %d\n", distance, mid);
		if (id[x] + 1 <= mid - 1) printf("t1.query(1, id[x] + 1, mid - 1) + dep[x] - id[x] = %d\n", t1.query(1, id[x] + 1, mid - 1) + dep[x] - id[x]);
		if (mid + 1 <= id[y] - 1) printf("t2.query(1, mid + 1, id[y] - 1) + dep[y] + id[y] = %d\n", t2.query(1, mid + 1, id[y] - 1) + dep[y] + id[y]);
		if (mid != id[x] && mid != id[y]) printf("min(dep[x] + far[mid] + mid - id[x], dep[y] + far[mid] + id[y] - mid) = %d\n", min(dep[x] + far[mid] + mid - id[x], dep[y] + far[mid] + id[y] - mid));
#endif
		printf("%d\n", ans);
	}
	return 0;
}
