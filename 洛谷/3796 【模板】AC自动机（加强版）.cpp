#include <bits/stdc++.h>
using namespace std;

int n, x, maxx, ans[160], t, p, tot = 1;
char a[1000010], c[160][80];
struct node {
	int ch[26], fail, id;
} e[100010];
void insert(char *a, int id) {
	int len = strlen(a);
	p = 1;
	for (int i = 0; i < len; i++) {
		x = a[i] - 'a';
		if (!e[p].ch[x]) e[p].ch[x] = ++tot;
		p = e[p].ch[x];
	}
	e[p].id = id;
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
		if (!p) p = 1;
		t = p;
		while (t != 1) {
//			printf("%d\n", t);
			ans[e[t].id]++;
			t = e[t].fail;
		}
	}
}

int main() {
	scanf("%d", &n);
	while (n) {
		for (int i = 1; i <= n; i++)
			scanf("%s", c[i]), insert(c[i], i);
		build_fail();
		scanf("%s", a);
		find(a);
		maxx = -1;
		for (int i = 1; i <= n; i++)
			if (ans[i] > maxx)
				maxx = ans[i];
		printf("%d\n", maxx);
		for (int i = 1; i <= n; i++)
			if (ans[i] == maxx)
				printf("%s\n", c[i]);
		scanf("%d", &n);
		memset(e, 0, sizeof(e));
		memset(ans, 0, sizeof(ans));
		tot = 1;
	}
	return 0;
}
