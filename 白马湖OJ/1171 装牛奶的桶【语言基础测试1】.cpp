#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, m, s, ans = 0;
    cin >> x >> y >> m;
    for (int i = 0; i * x <= m; i++) {
        s = i * x + (m - i * x) / y * y;
        if (s > ans) ans = s;
    }
    cout << ans << endl;
    return 0;
}