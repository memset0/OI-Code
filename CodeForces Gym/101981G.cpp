#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;

int fpow(int a, int b) {
    int s = 1;
    while (b) {
        if (b & 1) s = (long long)s * a % p;
        b >>= 1, a = (long long)a * a % p;
    }
    return s;
}

int main() {
    int t, n, ans;
	scanf("%d", &t);
    while (t--) {
        scanf("%d", &n), ans = 1;
        ans = (long long)ans * n % p;
        ans = (long long)ans * (n + 1) % p;
        ans = (long long)ans * (n + 2) % p;
        ans = (long long)ans * (n + 3) % p;
        ans = (long long)ans * fpow(24, p - 2) % p;
        printf("%d\n", ans);
    }
}
