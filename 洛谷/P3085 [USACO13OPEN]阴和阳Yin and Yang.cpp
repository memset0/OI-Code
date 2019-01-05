// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 1e5 + 10;
int n, u, v, w, cnt, sum, root, full_size; ll ans;
int siz[maxn], maxp[maxn], bkt[2][maxn << 1], tag[maxn << 1]; bool vis[maxn];
int tot = 2, hed[maxn], to[maxn << 1], val[maxn << 1], nxt[maxn << 1];
std::vector < int > rub;

struct status { int sum; bool flag; };
std::vector < status > vet;

#define f(a,b) (bkt[b][(a) + maxn])

void get_root(int u, int father) {
	siz[u] = 1, maxp[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father)
			get_root(v, u), siz[u] += siz[v], maxp[u] = std::max(maxp[u], siz[v]);
	maxp[u] = std::max(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void get_dis(int u, int father, int sum, bool flag) {
	vet.push_back((status){sum, sum ? (bool)tag[sum + maxn] : flag});
	flag |= !sum, ++tag[sum + maxn];
//	printf("get dis %d %d %d\n", u, sum, (bool)(tag[sum + maxn] - 1));
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father)
			get_dis(v, u, sum + val[i], flag);
	--tag[sum + maxn];
}

void solve(int u) {
//	printf("===== solve %d =====\n", u);
	vis[u] = 1, sum = 0, rub.clear(), rub.push_back(0);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
//			printf("----- %d -----\n", v);
			cnt = 0, vet.clear(), ++tag[maxn], get_dis(v, u, val[i], 0), --tag[maxn];
			for (std::vector < status > ::iterator it = vet.begin(); it != vet.end(); it++) {
				// printf("+ %d - %d\n", f(-it->sum, 1), it->flag ? 0 : f(-it->sum, 0)),
				if (it->sum) ans += f(-it->sum, 1) - (it->flag ? 0 : f(-it->sum, 0));
				else ++cnt, ans += sum + it->flag;
			}
			sum += cnt;
			for (std::vector < status > ::iterator it = vet.begin(); it != vet.end(); it++) if (it->sum) {
				++f(it->sum, 1); if (!it->flag) ++f(it->sum, 0);
				rub.push_back(it->sum);
			}
		}
	for (std::vector < int > ::iterator it = rub.begin(); it != rub.end(); it++)
		f(*it, 0) = f(*it, 1) = 0;
//	printf(">>> %lld\n", ans);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) root = 0, maxp[0] = full_size = siz[v], get_root(v, u), solve(root);
}

void main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w), w = w ? 1 : -1;
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	root = 0, maxp[0] = full_size = n, get_root(1, 0), solve(root);
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }
