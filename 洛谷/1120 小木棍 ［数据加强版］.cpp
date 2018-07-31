#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
int n, m, tn, sum = 0, a[maxn];
bool find_ans = false, find_this, dis[maxn];
bool cmp(int x, int y) {
    return x > y;
}
void DFS(int u, int x) {
    if (x == 0) {
        find_this = 1;
        return ;
    }
    if (x < 0) return;
    for (int i = u; i <= n && !find_this; i++)
        if (!dis[i]) {
            dis[i] = 1;
 			DFS(i + 1, x - a[i]);
 			if (!find_this) dis[i] = 0;
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
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
    for (m = 1; m <= sum && !find_ans; m++)
        if (sum % m == 0) {
            memset(dis, 0, sizeof(dis));
            find_ans = true;
            for (int i = 1; i <= (sum / m); i++) {
                find_this = false;
                DFS(1, m);
                if (!find_this) {
                    find_ans = false;
                    break;
                }
            }
//			for (int i = 1; i <= n; i++)
//				printf("%d", dis[i]);
//			puts("");
        }
    printf("%d\n", m - 1);
    return 0;
}
