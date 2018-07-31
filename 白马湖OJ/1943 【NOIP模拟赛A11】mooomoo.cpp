#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 30;
const int maxf = 10000110;
int n, m, ans = 0, a[maxn], b[maxm], t[maxn], f[maxf];
bool my_sort(int a, int b) {
    return a > b;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]), f[b[i]] = 1;
    sort(b + 1, b + m + 1, my_sort);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
     
//  for (int i = 1; i <= n; i++)
//      for (int j = i + 1, k = a[i] - 1; j <= n && k > 0; j++, k--) 
//          a[j] -= k;
    for (int i = n; i > 1; i--)
        if (a[i - 1] > 0) a[i] -= a[i - 1] - 1;
    int maxx = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] > maxx) maxx = a[i];
 
    for (int i = 0; i <= maxx; i++)
        if (f[i])
            for (int j = 1; j <= m; j++)
                if (f[i + b[j]] == 0 || f[i + b[j]] > f[i] + 1) f[i + b[j]] = f[i] + 1;
                 
//  for (int i = 1; i <= n; i++)
//      cout << a[i] << " ";
//  puts("");
//  for (int i = 1; i <= 20; i++)
//      cout << f[i] << " ";
//  puts("");
    for (int i = 1; i <= n; i++) {
        int x = f[a[i]];
//      cout << x << endl;
        if (x == 0 && a[i] != 0) {
//          cout << x << " " << i << endl;
            cout << -1 << endl;
            return 0;
        } else ans += x;
    }
    cout << ans << endl;
    return 0;
}