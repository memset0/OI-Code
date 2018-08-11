// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 30;
int n, m, k, x, ans;
struct node {
	int val, x, y;
	node (int __val = 0, int __x = 0, int __y = 0) {
		val = __val, x = __x, y = __y;
	}
	bool operator < (const node &b) const {
		return val > b.val;
	}
};
vector < node > p;
int dis(node a, node b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	
	n = read(), m = read(), k = read() - 4;
	p.push_back(node(0, 0, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (x = read())
				p.push_back(node(x, i, j));
	sort(p.begin() + 1, p.end());
	*p.begin() = node(0, 0, (*++p.begin()).y);
	for (auto it = ++p.begin(); it != p.end(); it++){
		auto bf = it - 1;
//		printf("%d %d %d\n", (*bf).val, (*bf).x, (*bf).y);
//		printf("%d %d %d\n", (*it).val, (*it).x, (*it).y);
//		printf(">>> %d %d %d\n", dis(*bf, *it), (*it).y, k);
		if (dis(*bf, *it) + (*it).y <= k) {
			k -= dis(*bf, *it);
			ans += (*it).val;
		} else break;
	}
	printf("%d\n", ans);
	
	return 0;
}

