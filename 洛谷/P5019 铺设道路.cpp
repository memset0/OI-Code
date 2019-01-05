#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
int main() {
    for (scanf("%d", &n); n--; ) {
        scanf("%d", &b);
        if (b - a > 0) ans += b - a;
        a = b;
    }
    printf("%d\n", ans);
    return 0;
}