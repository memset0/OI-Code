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
int main() {
    ll ans = 0;
    for (int i = 1; i <= 3e6; i++)
    	ans ^= read();
    printf("%lld\n", ans);
	return 0;
}