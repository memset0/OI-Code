#include <bits/stdc++.h>
using namespace std;
const int maxn = 70010;
const int maxl = 200010;
const int maxt = 1000010;
int n, l, t, k, w, p, a[maxn];
char c;
int main() {
    cin >> l >> t >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &k, &c);
        int tt = t, kk;
        while (tt > 0) {
            if (c == 'D') {
                kk = k;
                k += min(tt, l - kk);
                tt -= min(tt, l - kk);
                if (k == l) c = 'L';
            }
            else {
                kk = k;
                k -= min(tt, kk);
                tt -= min(tt, kk);
                if (k == 0) c = 'D';
            }
//          cout << k << " " << tt << " " << kk << " " << c << endl;
        }
        a[i] = k;
//      cout << i << " " << k << " " << a[i] << endl;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
    return 0;
}