#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
const int maxm = 51;
int n, m, s, tn, sum = 0, a[maxn], cnt[maxn * maxm];
bool find_ans = false, find_this, dis[maxn];
bool cmp(int x, int y) {
    return x > y;
}
void DFS(int u, int x) {
	cout << ">>> " << u << " " << x << endl;	
//	for (int i = 1; i <= m; i++)
//		printf("%d ", cnt[i]);
//	puts("");
	if (u > n || x > m) {
		find_ans = true;
		return ;
	}
	if (cnt[x] == s) {
		DFS(u, x + 1);
		return ;
	}
	for (int i = x; i <= u; i++)
		if (cnt[i] + a[u] <= s) {
			cnt[i] += a[u];
			DFS(u + 1, x);
			cnt[i] -= a[u];
		}
}
int main() {
    scanf("%d", &tn);
    for (int i = 1; i <= tn; i++) {
        scanf("%d", &a[++n]);
        if (a[n] > 50) n--;
        else sum += a[n];
    }
    sort(a + 1, a + n + 1, cmp);
    for (s = 1; s <= sum; s++)
    	if (sum % s == 0) {
    		m = sum / s;
    		DFS(1, 1);
    		for (int i = 1; i <= m; i++)
    			printf("%d ", cnt[i]);
    		puts("");
    		system("pause");
    		if (find_ans) {
    			printf("%d\n", s);
    			return 0;
			}
		}
    return 0;
}
