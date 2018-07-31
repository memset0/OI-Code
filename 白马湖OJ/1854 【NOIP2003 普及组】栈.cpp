#include <bits/stdc++.h> 
using namespace std;
const int maxn = 20;
long long n, f[maxn];
int main() {
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) 
        for (int j = 0; j < i; j++)
            f[i] += f[j] * f[i - j - 1];
    cout << f[n];
    return 0;
}