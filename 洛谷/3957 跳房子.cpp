#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn = 500010;
int n, d, k, l, r, f[500010], a[500010], v[500010];
struct Queue {
	int a[maxn], l = 1, r = 0;
	int size() {
		return r - l + 1;
	}
	void push(int x) {
		while (f[x] >= f[a[r]] && size())  r--;
		a[++r] = x;
		return ;
	}
	void pop() {
		l++;
		return ;
	}
	void clean() {
		memset(a, 0, sizeof(a));
		l = 1, r = 0;
		return ;
	}
	int operator [] (int k) {
		return a[k];
	}
} q;
//	printf("[FUN]check(%d)\n", g);
//bool check(int g) {
//	l = max(1, d - g), r = d + g;
//	memset(f, 0, sizeof(f)), q.clean();
//	f[0] = 0; q.push(0);
//	for (int i = 1; i <= n; i++) {
//		f[i] = -INF;
//		for (int j = q.l; j <= q.r; j++) {
//			if (l <= a[i] - a[q[j]] && a[i] - a[q[j]] <= r) {
//				f[i] = max(f[i], f[q[j]] + v[i]);
//				q.push(i);
//				if (f[i] >= k) return true;
//				break;
//			}
//		}
//	}
//	return false;
//}
#define h q.l
#define t q.r
bool check(int g){
    int p = 0; q.clean(); q.push(0);
    for(int i = 1; i <= n; i++) f[i] = -INF;
    for(int i = 1; i <= n; i++){
        while(a[i] - a[p] >= max(d - g, 1) && p < i) q.push(p++);
        while(a[i] - a[q[h]] > d + g && h <= t) h++;
        if(h > t || f[q[h]] == -INF) continue; else f[i] = f[q[h]] + v[i]; 
        if(f[i] >= k) return 1;
    }
    return 0;
}
//					printf("    f[i:%d] = %d; f[j:%d] = %d;\n", i, f[i], q[j], f[q[j]]);
//					printf("      q[%d] = {", q.r - q.l + 1);
//					for (int i = q.l; i <= q.r; i++)
//						printf("%d, ", q[i]);
//					puts("}");
//			printf("  %d %d %d %d %d\n", i, a[i] - a[q[j]], l, r, l <= a[i] - a[q[j]] && a[i] - a[q[j]] <= r);
int main() {
	freopen("testdata.in", "r", stdin);
	scanf("%d%d%d", &n, &d, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &v[i]);
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		if (v[i] > 0) sum += v[i];
	if (sum < k) {
		printf("-1\n");
		return 0;
	}
	int ll = 0, rr = 100000000, mid;
	while (ll + 4 < rr) {
		mid = (ll + rr) / 2;
		if (check(mid)) rr = mid;
		else ll = mid;
	}
	for (int i = ll; i <= rr; i++)
		if (check(i)) {
			printf("%d\n", i);
			return 0;
		}
	return 0;
}
