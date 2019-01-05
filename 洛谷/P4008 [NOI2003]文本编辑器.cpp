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

const int maxn = 2000010;
int u, t, k, x, y, z, at, rt, top, tot;
char c, op, tp;
int stk[maxn], rnd[maxn], val[maxn], ch[maxn][2], siz[maxn];

il void update(int u) { siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }
il int new_node(int v) { val[++tot] = v, rnd[tot] = rand(), siz[tot] = 1; return tot; }

void split(int u, int k, int &x, int &y) {
//	printf("split %d %d : %d\n", u, k, siz[u]);
	if (!u) return (void)(x = y = 0);
	if (k <= siz[ch[u][0]])
		y = u, split(ch[y][0], k, x, ch[y][0]);
	else
		x = u, split(ch[x][1], k - siz[ch[u][0]] - 1, ch[x][1], y);
	update(u);
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		ch[x][1] = merge(ch[x][1], y);
		return update(x), x;
	} else {
		ch[y][0] = merge(x, ch[y][0]);
		return update(y), y;
	}
}

void dfs(int u) {
	if (ch[u][0]) dfs(ch[u][0]);
	putc(val[u]);
	if (ch[u][1]) dfs(ch[u][1]);
}

void main() {
	for (read(t); t--; ) {
		while (op = getc(), !isupper(op));
		while (tp = getc(), islower(tp));
//		printf(">>> %c\n", op);
		switch (op) {
			case 'I':
/*				top = 0;
				for (read(k); k--; ) {
					while (c = getc(), c < 32 || c > 126);
					u = new_node(c);
					while (top && rnd[u] < rnd[stk[top]])
						ch[u][0] = top--;
					update(u);
					if (top) ch[stk[top]][1] = u, update(stk[top]);
					printf("%c >> ", c);
					for (int i = 1; i <= top; i++)
						print(stk[i]), putc(' ');
					putc('\n');
					stk[++top] = u;
				}
				while (top) update(stk[top--]);
				for (int i = 1; i <= 26; i++)
					printf("%d %c : %d %d : %d %d\n", i, val[i], rnd[i], siz[i], ch[i][0], ch[i][1]);
				dfs(stk[1]), putc('\n');
				split(rt, at, x, y);
				rt = merge(x, merge(stk[1], y));
				dfs(rt), putc('\n');*/
				split(rt, at, x, y);
				for (read(k); k--; ) {
					while (c = getc(), c < 32 || c > 126);
					x = merge(x, new_node(c));
				}
				rt = merge(x, y);
				break;
			case 'D':
				read(k), split(rt, at, x, y), split(y, k, y, z);
				rt = merge(x, z);
				break;
			case 'G':
				read(k), split(rt, at, x, y), split(y, k, y, z);
				dfs(y), putc('\n'), rt = merge(x, merge(y, z));
				break;
			case 'M': at = (read(k), k); break;
			case 'P': --at; break;
			case 'N': ++at; break;
		}
//		printf("%d : ", at), dfs(rt), putc('\n');
	}
}

} int main() { return ringo::main(), 0; }
