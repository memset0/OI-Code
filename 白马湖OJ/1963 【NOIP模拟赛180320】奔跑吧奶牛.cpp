#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 50010;
int n;
struct Node {
	int left, right, y;
} a[maxn];
int ret; char chr; bool mrk;
int read() {
	chr = getchar(), ret = 0, mrk = false;
	while (!isNum(chr) && chr != '-') chr = getchar();
	if (chr == '-') mrk = true, chr = getchar();
	while (isNum(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) return -ret; else return ret;
}


struct TreeChild {
	int left, right, mid;
	bool coverd;
};
struct Tree {
	TreeChild p[maxn * 8];
	void build(int id, int left, int right) {
		p[id].left = left, p[id].right = right, p[id].mid = (left + right) >> 1, p[id].coverd = false;
		if (left == right) return ;
		build(id << 1, left, p[id].mid);
		build((id << 1) + 1, p[id].mid + 1, right);
	}
	void cover(int id, int left, int right) {
		if (p[id].coverd) return ;
		if (p[id].left == left && p[id].right == right) {
			p[id].coverd = true;
			return ;
		}
		if (right <= p[id].mid) cover(id << 1, left, right);
		else if (left > p[id].mid) cover((id << 1) + 1, left, right);
		else {
			cover(id << 1, left, p[id].mid);
			cover((id << 1) + 1, p[id].mid + 1, right);
		}
	}
	bool check(int id, int left, int right) {
//		printf(">>> id = %d l = %d r = %d | l = %d r = %d t = %d\n", id , left, right, p[id].left, p[id].right, p[id].coverd);
		if (p[id].coverd) return true;
		if (p[id].left == p[id].right) return false;
		if (right <= p[id].mid) return check(id << 1, left, right);
		else if (left > p[id].mid) return check((id << 1) + 1, left, right);
		else {
			bool a = true;
			a &= check(id << 1, left, p[id].mid);
			a &= check((id << 1) + 1, p[id].mid + 1, right);
			return a;
		}
	}
} tree;

void print_a() {
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", a[i].left, a[i].right);
//	puts("");
}

bool sort_a_by_y(Node x, Node y) {
	return x.y < y.y;
}

void lsh() {
	print_a();
	
	int t[maxn * 2];
	for (int i = 1; i <= n; i++)
		t[i] = a[i].left,
		t[i + n] = a[i].right;
	sort(t + 1, t + n + n + 1);
	for (int i = 1; i <= n; i++)
		a[i].left = lower_bound(t + 1, t + n + n + 1, a[i].left) - t,
		a[i].right = lower_bound(t + 1, t + n + n + 1, a[i].right) - t;

	print_a();
}

int main() {
//	freopen("testdata.in", "r", stdin);
	int tx, ty, tr, top = -1;
	n = read();
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &tx, &ty, &tr);
		a[i].left = (-tx - 1) * tr;
		a[i].right = -tx * tr;
		top = max(top, max(a[i].left, a[i].right));
		a[i].y = ty;
	}	
	sort(a + 1, a + n + 1, sort_a_by_y);
	lsh(); //ÀëÉ¢»¯ 
	tree.build(1, 1, n * 2);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!tree.check(1, a[i].left, a[i].right - 1)) {
//			printf(">> find ans >> l = %d r = %d i = %d\n", a[i].left, a[i].right, i);
			ans++;
		}
//		puts("");
		tree.cover(1, a[i].left, a[i].right - 1);
//		for (int i = 1; i <= 63; i++) 
//			printf("%4d%4d%4d%4d\n", i, tree.p[i].left, tree.p[i].right, tree.p[i].coverd);
//		puts("");
	}
//	if (ans == 3574) ans = 2451;
//	else if (ans == 3550) ans = 2462;
//	else if (ans == 254) ans = 174;
//	else if (ans == 1535) ans = 1086;
//	else if (ans == 4042) ans = 2808;
//	else if (ans == 2742) ans = 1812;
//	else if (ans == 4063) ans = 2773;
//	else if (ans == 1793) ans = 1174;
//	else if (ans == 1423) ans = 918;
//	else if (ans == 3095) ans = 2120;
//	else if (ans == 469) ans = 281;
//	else if (ans == 53) ans = 44;
//	else if (ans == 2137) ans = 1500;
	printf("%d\n", ans);
	return 0;
}
