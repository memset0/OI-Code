#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int main() {
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1 - i; j++) {
                k++;
                printf("%4d", k);
            }
        puts("");
    } 
    return 0;
}