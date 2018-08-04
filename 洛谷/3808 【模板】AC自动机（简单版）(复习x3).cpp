#include <bits/stdc++.h>
using namespace std;

int n, x, ans, t, p, tot = 1;
char a[1000010];
struct node {
	int ch[26], fail, sum;
	bool used;
} e[5000010];
void insert(char *a) {
	int len = strlen(a);
	p = 1;
	for (int i = 0; i < len; i++) {
		x = a[i] - 'a';
		if (!e[p].ch[x]) e[p].ch[x] = ++tot;
		p = e[p].ch[x];
	}
	e[p].sum++;
}
void build_fail() {
	queue < int > q;
	q.push(1);
	while (q.size()) {
		p = q.front(), q.pop();
		for (int i = 0; i < 26; i++)
			if (e[p].ch[i]) {
				if (p == 1) e[e[p].ch[i]].fail = 1;
				else {
					t = e[p].fail;
					while (t) {
						if (e[t].ch[i]) {
							e[e[p].ch[i]].fail = e[t].ch[i];
							break;
						}
						t = e[t].fail;
					}
					if (!t) e[e[p].ch[i]].fail = 1;
				}
				q.push(e[p].ch[i]);
			}
	}
}
void find(char *a) {
	int len = strlen(a);
	p = 1;
	for (int i = 0; i < len; i++) {
		x = a[i] - 'a';
		while (!e[p].ch[x] && p != 1) p = e[p].fail;
		p = e[p].ch[x];
		if (!p) p = 0;
		t = p;
		while (t != 1) {
			if (e[t].used) break;
			ans += e[t].sum;
			e[t].used = 1;
			t = e[t].fail;
		}
	}
}

int main() {
	scanf("%d", &n);
	while (n--) scanf("%s", a), insert(a);
	build_fail();
	scanf("%s", a), find(a);
	printf("%d\n", ans);
	return 0;
}
