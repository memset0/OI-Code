#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 40 - i; j++)
            putchar(' ');
        for (int j = 1; j <= i; j++)
            printf("%d", j);
        for (int j = i - 1; j > 0; j--)
            printf("%d", j);
        puts("");
    }
    return 0;
}