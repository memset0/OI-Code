#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = std::getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::m = -1, r::c = getchar(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
using namespace std;
namespace r {
	char c;
	int m;
}

const int maxn = 110;

int n, cnt, dis[maxn];
bool findans; 
struct Node {
	char a[maxn];
	int l, linkin, tag, order, cnt = 1;
	vector < int > g;
} a[maxn];

queue < int > q;

bool check(Node &x, Node &y) {
	if (x.l > y.l) return false;
	bool mark;
	for (int i = 1; i + x.l - 1 <= y.l; i++) {
		mark = true;
		for (int j = 1; j <= x.l; j++)
			if (x.a[j] != y.a[i + j - 1]) {
				mark = false;
				break;
			}
		if (mark) return true;
	}
	return false;
}

bool cmp(Node a, Node b) {
	return a.order > b.order;
}

int main() {
	
	read(n);
	
	if (n == 0) {
		printf("YES\n");
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i].a + 1);
		a[i].l = strlen(a[i].a + 1);
		for (int j = 1; j < i; j++)
			if (a[i].l == a[j].l && check(a[i], a[j])) {
				a[j].cnt++;
				i--, n--;
				break;
			}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) {
				if (check(a[i], a[j])) {
					a[j].g.push_back(i);
					a[i].tag += 1;
				}
			}
	
//	for (int i = 1; i <= n; i++)
//		cout << a[i].linkin << " " ;
//	puts("");
	for (int i = 1; i <= n; i++)
		if (a[i].tag == 0) {
			
			memset(dis, 0, sizeof(dis));
			for (int i = 1; i <= n; i++)
				a[i].linkin = a[i].tag;
			
//			q.clean();			
			q.push(i);
			
			int u;
			while (q.size()) {
				u = q.front(), q.pop();
				dis[u] = 1;
				a[u].order = ++cnt;
				for (int i = 0; i < a[u].g.size(); i++) {
					if (!dis[a[u].g[i]] && a[a[u].g[i]].linkin) {
//						cout << u << " " << a[u].g[i] << endl;
						a[a[u].g[i]].linkin--;
						if (a[a[u].g[i]].linkin == 0)
							q.push(a[u].g[i]);
					}
				}
			}
			
		//	for (int i = 1; i <= n; i++) {
				
//			puts("");
			
			findans = true;
			for (int i = 1; i <= n; i++)
				if (!dis[i]) {
					findans = false;
					break;
				}
				
			if (findans) {
				sort(a + 1, a + n + 1, cmp);
				printf("YES\n");
				for (int i = 1; i <= n; i++)
					for (int k = 1; k <= a[i].cnt; k++)
						printf("%s\n", a[i].a + 1);
				return 0;
			}
		}
		
	printf("NO\n");
	return 0;
}
