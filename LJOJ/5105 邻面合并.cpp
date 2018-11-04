#include <bits/stdc++.h>
namespace wyl {

void read(int &x) {
    register char c = getchar();
    register bool f = false;
    while (!isdigit(c)) {
        f ^= c == '-';
        c = getchar();
    }
    x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

using std::vector;

const int maxn = 102, maxm = 10;
const int inf = 1000000000;

int n, m, lc, rc, ls, rs, cnt, now, min, ans;
int a[maxn][maxm], l[maxm], r[maxm], at[maxm];

struct status {
	int x, v;
};
vector < status > vet[2];

int zip(int *a) {
	int ret = 0;
	for (int i = 1; i <= m; i++)
		ret = (ret << 2) | a[i];
	return ret;
}

void unzip(int x, int *a) {
	for (int i = m; i >= 1; i--)
		a[i] = x & 3, x >>= 2;
}

int main() {
	// freopen("merging.in", "r", stdin);
	// freopen("merging.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	vet[0].push_back((status){0, 0});
	l[m + 1] = r[m + 1] = -1;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= m; j++)
			if (a[i][j])
				at[++cnt] = j;
		vet[i & 1].clear();
		for (int i = 1; i <= m; i++)
			r[i] = 0;
		for (int x = 0; x < (1 << cnt); x++) {
			for (int i = 1; i <= cnt; i++)
				r[at[i]] = 1 + (x & (1 << (i - 1)) ? 1 : 0);
			min = inf;
			for (vector < status > ::iterator it = vet[i & 1 ^ 1].begin(); it != vet[i & 1 ^ 1].end(); it++) {
				unzip(it->x, l), now = 0;
				lc = rc = -1, ls = -1, rs = -2;
				for (int i = 1; i <= m + 1; i++) {
					if (lc != l[i] && rc != r[i] && ls == rs && lc && rc)
						--now;
					if (lc == l[i]) ls++;
					else lc = l[i], ls = 1;
					if (rc == r[i]) rs++;
					else {
						if (rc == 1 || rc == 2) ++now;
						rc = r[i], rs = 1;
					}
				}
//				for (int i = 1; i <= m; i++) printf("%d ", l[i]); printf("| ");
//				for (int i = 1; i <= m; i++) printf("%d ", r[i]); printf("| %d %d\n", it->v, now);
				min = std::min(min, it->v + now);
			}
			vet[i & 1].push_back((status){zip(r), min});
		}
//		for (vector < status > ::iterator it = vet[i & 1].begin(); it != vet[i & 1].end(); it++)
//			printf("%d : %d %d\n", i, it->x, it->v);
	}
	ans = inf;
	for (vector < status > ::iterator it = vet[n & 1].begin(); it != vet[n & 1].end(); it++)
		ans = std::min(ans, it->v);
	printf("%d\n", ans);
    
    return 0;
}

} int main() { wyl::main(); return 0; }
