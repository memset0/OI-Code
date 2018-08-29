// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int N = 10000000;

ll p, n, ans;

ll inv2, inv6;

ll phi[N], sum[N];
ll pri[N];
bool vis[N];

map < ll, ll > mp;

ll inv(ll x) {
    if (x == 0 || x == 1) return 1;
    return (p - p / x) * inv(p % x) % p;
}

ll sum1(ll x) {
    // x %= p;
    return (x) % p * (x + 1) % p * inv2 % p;
}

ll sum2(ll x) {
    // x %= p;
    return (x) % p * (x + 1) % p * ((x << 1LL) % p + 1) % p * inv6 % p;
}

ll sum3(ll x) {
    // x %= p;
    return sum1(x) * sum1(x) % p;
}

void init() {
    inv2 = inv(2);
    inv6 = inv(6);

    phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            phi[i] = i - 1;
            pri[++pri[0]] = i;
        }
        for (int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j]) {
                phi[i * pri[j]] = (phi[i] * phi[pri[j]]) % p;
            } else {
                phi[i * pri[j]] = (phi[i] * pri[j]) % p;
                break;
            }
        }
    }

    for (int i = 1; i < N; i++)
        sum[i] = (sum[i - 1] + (phi[i] * i % p * i % p)) % p;
}

ll S(ll n) {
    if (n < N) return sum[n];
    if (mp[n]) return mp[n];
    ll ans = sum3(n);
    for (ll l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ll tmp = sum2(r) - sum2(l - 1) % p;
        tmp = tmp * S(n / l) % p;
        ans = (ans - tmp) % p;
        // if (ans < 0) printf("%lld\n", ans);
    }
    // printf("S(%lld) = %lld\n", n, ans);
    return mp[n] = ans;
}

int main() {
    // freopen("INPUT", "r", stdin);
    // freopen("OUTPUT", "w", stdout);

    p = read(), n = read();

    init();

    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ll tmp = (S(r) - S(l - 1)) % p;
        tmp = tmp * sum3(n / l) % p;
        ans = (ans + tmp) % p;
        // printf("(%lld, %lld)\n", l, r);
    }

    printf("%lld\n", (ans + p) % p);

    return 0;
}