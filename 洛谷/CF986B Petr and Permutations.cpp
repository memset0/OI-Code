// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 1000010;

#define lowbit(x) ((x)&(-(x)))

int n, ans, a[maxn], s[maxn];

void add(int k) {
	for (int i = k; i <= n + 1; i += lowbit(i))
		s[i] += 1;
}

int ask(int k) {
	int ans = 0;
	for (int i = k; i >= 1; i -= lowbit(i))
		ans += s[i];
	return ans;
}

int main() {
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	
	for (int i = 1; i <= n; i++) {
		ans = (ans + ask(n + 1) - ask(a[i] + 1)) & 1;
		add(a[i] + 1);
//		cout << ask(n + 1) - ask(a[i] + 2) << endl;
	}
	
//	cout << ans << " " << n << endl;
	
	if ((ans & 1) == (n & 1)) puts("Petr");
	else puts("Um_nik");
	
	return 0;
}

