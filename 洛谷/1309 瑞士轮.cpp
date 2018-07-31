#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100010;
int n, m, q;
struct S{
    int i, w, k;
} a[2 * maxn], b[2 * maxn], t;
bool cmp(S a, S b) {
    if (a.w == b.w) return a.i < b.i;
    return a.w > b.w;
}
void msort() {
	int i = 1, j = 2, k = 1;
	while (i <= 2 * n - 3 && j <= 2 * n - 2) {
		if (cmp(a[i], a[j])) {
			b[k++] = a[i];
			i += 2;
		} else {
			b[k++] = a[j];
			j += 2;
		}
	}
	while (i <= 2 * n - 3) {
		b[k++] = a[i];
		i += 2;
	}
	while (j <= 2 * n - 2) {
		b[k++] = a[j];
		j += 2;
	}
	for (int i = 1; i <= 2 * n; i++)
		a[i] = b[i];
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= 2 * n; i++)
        a[i].i = i;
    for (int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i].w);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i].k);
    sort(a + 1, a + 2 * n + 1, cmp);
    for (int i = 1; i <= m; i++) {
        for (int i = 1; i <= 2 * n; i += 2)
            if (a[i].k > a[i + 1].k) {
				a[i].w += 1;
			} else {
            	a[i + 1].w += 1;
            	t = a[i];
            	a[i] = a[i + 1];
            	a[i + 1] = t;
			}
		for (int i = 1; i <= 2 * n; i++)
			printf("i = %d; w = %d; k = %d\n", a[i].i, a[i].w, a[i].k);
		puts("");
		msort();
    }
    cout << a[q].i << endl;
    return 0;
}
