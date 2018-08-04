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

int n, x, ans;
char a[1000010];
struct node {
	node *next[26], *fail;
	int sum; bool used;
	node() {
		memset(next, 0, sizeof(next));
		fail = 0, sum = 0, used = 0;
	}
} *root, *newd, *t, *p;
void insert(char *a) {
	int len = strlen(a);
	p = root;
	for (int i = 0; i < len; i++) {
		x = a[i] - 'a';
		if (!p->next[x]) p->next[x] = new node();
		p = p->next[x];
	}
	p->sum++;
}
void build_fail() {
	queue < node* > q;
	q.push(root);
	while (q.size()) {
		p = q.front(), q.pop();
		for (int i = 0; i < 26; i++)
			if (p->next[i]) {
				if (p == root) p->next[i]->fail = root;
				else {
					t = p->fail;
					while (t) {
						if (t->next[i]) {
							p->next[i]->fail = t->next[i];
							break;
						}
						t = t->fail;
					}
					if (!t) p->next[i]->fail = root;
				}
				q.push(p->next[i]);
			}
	}
}
void find(char *a) {
	int len = strlen(a);
	p = root;
	for (int i = 0; i < len; i++) {
		x = a[i] - 'a';
		while (!p->next[x] && p != root) p = p->fail;
		p = p->next[x];
		if (!p) p = root;
		t = p;
//		printf("%d %d\n", t, root);
		while (t != root) {
			if (t->used) break;
			ans += t->sum;
			t->used = 1;
			t = t->fail;
//			printf("%d\n", t);
		}
	}
}

int main() {
	root = new node();
	scanf("%d", &n);
	while (n--) scanf("%s", a), insert(a);
	build_fail();
	scanf("%s", a), find(a);
	printf("%d\n", ans);
	return 0;
}
