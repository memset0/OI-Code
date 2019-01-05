// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
int main() {
    double n;
    scanf("%lf", &n);
    printf("%.12lf\n", n * (n + 1) / (2 * (2 * n - 1)));
    return 0;
}