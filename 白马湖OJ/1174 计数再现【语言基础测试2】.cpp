#include <bits/stdc++.h>
using namespace std;
const int maxm = 3010;
int n, a, b[maxm];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        a += 1000;
        b[a]++;
    }
    for (int i = 1; i < 3000; i++) 
        if (b[i]) printf("%d %d\n", i - 1000, b[i]);
    return 0;
}