#include <bits/stdc++.h> 
using namespace std;
const int maxm = 10010;
int n, m, l, r, a[maxm];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r);
        for (int i = l; i <= r; i++)
            a[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        if (!a[i]) ans++;
    cout << ans << endl;
    return 0;
}