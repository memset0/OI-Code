// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Mod = 19260817;

ll a, b;

ll read() {
    ll x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x * 10 + c - '0') % Mod, c = getchar();
    return x;
}

ll inv(ll x) {
	if (x == 0 || x == 1) return 1;
	return (Mod - Mod / x) * inv(Mod % x) % Mod;
}

int main() {
	a = read(), b = read();
	if (!b) printf("Angry!\n");
	else printf("%lld\n", a * inv(b) % Mod);
	return 0;
}
