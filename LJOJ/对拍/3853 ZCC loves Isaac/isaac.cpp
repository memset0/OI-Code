#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x; 
}
const int maxn = 1000010;
int n, u, l = 1, r, ans1, ans2, flag, flag_ans, nxt[maxn], cnt[maxn], q[maxn];
bool inq[maxn], die[maxn], out[maxn];
void print(int *a, int n) {
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void printb(char *s, bool *a, int n) {
	cout << s << " = ";
	for (int i = 1; i <= n; i++)
		cout << (int)a[i] << " ";
	cout << endl;
}
int main() {
//	freopen("data.txt", "r", stdin);
	n = read(), ans2 = n;
	for (int i = 1; i <= n; i++)
		nxt[i] = read(), cnt[nxt[i]]++;
	for (int i = 1; i <= n; i++)
		if (!cnt[i]) q[++r] = i, inq[i] = 1, ans2--;
	while (l <= r) {
		u = q[l++], out[nxt[u]] = 1, die[nxt[u]] |= die[u] ^ 1;
		if (!--cnt[nxt[u]])	q[++r] = nxt[u], inq[nxt[u]] = 1;
	}
//	printb("die", die, n), printb("out", out, n), printb("inq", inq, n), cout << endl;
	for (int i = 1; i <= n; i++)
		if (!inq[i] && die[i]) {
			u = i, flag = 0;
			if (die[u]) inq[u] = 1, u = nxt[u];
			while (1) {
				while (die[u] && !inq[u]) inq[u] = 1, u = nxt[u];
				if (inq[u]) break;
				inq[u] = 1;
				u = nxt[u];
				if (inq[u]) break;
				inq[u] = die[u] = 1;
				u = nxt[u];
			}
		}
	for (int i = 1; i <= n; i++)
		if (!inq[i]) {
			if (i == nxt[i]) die[i] = inq[i] = 1;
			else {
				u = i, flag = 1, flag_ans = 0;
				while (!inq[u]) {
					inq[u] = 1, die[u] = flag, flag ^= 1, flag_ans |= out[u];
					/*cout << u << endl, printb(inq, n), printb(die, n), */
					u = nxt[u];
				}
				ans2 -= flag_ans ^ 1; 
			}
		}
//	printb("inq", inq, n);
//	printb("die", die, n);
//	cout << endl; 
	for (int i = 1; i <= n; i++)
		if (die[i]) ans1++;
	printf("%d %d\n", ans1, ans2);
	return 0;
}
