#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int read(void);
int n;
struct Node {
	int val, fa, ch[2], cnt, siz;
} e[maxn];
int identify(Node x) {
	if (e[x.father].ch[0] == x) return 0;
	else return 1;
}
int update(int x) {
	e[x].siz = e[x.ch[0]].siz + e[x.ch[1]].siz + e[x].cnt;
}
int connect(int ch, int fa, int cid) {
	e[ch].fa = fa;
	e[fa].ch[cid] = ch;
}
int rotate(int x) {
	int y = e[x].fa, m = e[y].fa, ycid = identify(x), mcid = identify(y), c = e[x].ch[ycid ^ 1];
	connect(c, y, yid), connect(y, x, (yid ^ 1)), connect(x, m, mid);
	update(y), update(x); //先更新y，因为y是x的孩子节点 
}
int splay(int at, int to) {
	to = e[to].fa;
	while (e[at].fa != e[to].fa) {
		int up = e[at].fa;
		if (e[up].fa == to) rotate(at); //当且节点旋转一次即可满足要求 
		else if (identify(at) == identify(up)) {
			rotate(up);
			rotate(at);
		} else {
			rotate(at);
			rotate(at);
		}
	} 
}
int main() {
	int x, t;
	t = read();
	while (t--) {
		x = read();
		if (x == 1) {
			x = read();
		}
	}
	return 0;
}

int ret; char chr; bool mrk;
int read(void) {
	ret = 0, chr = getchar(), mrk = 0;
	while (!isdigit(chr) && chr != '-') chr = getchar();
	if (chr == '-') mrk = 1, chr = getchar();
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) return -ret; else return ret;
}
