#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, a[maxn];
char c;
int main() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        c = getchar();
        if (c == 'W') a[i] = 0;
        else a[i] = 1;
    }
    int cnt, ans = -1;
    for (int i = 0; i <= n; i++) {
        cnt = 0;
        for (int j = 1; j <= i; j++)
            if (a[j] != 0) cnt++;
        for (int j = i + 1; j <= n; j++)
            if (a[j] != 1) cnt++;
        if (ans == -1 || cnt < ans) ans = cnt;
//      cout << i << " " << cnt << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}