// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
int n, x, y, s;
int main() {
    scanf("%d%d", &n, &y), s = y;
    for (int i = 2; i <= n; i++) {
        x = y, scanf("%d", &y);
        if (y > x) s += y - x;
    }
    printf("%d", s);
}