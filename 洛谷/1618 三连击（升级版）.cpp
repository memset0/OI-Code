#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans = 0, f[10];
bool mark;
int main() {
	cin >> a >> b >> c;
	for (int i = 1; a * i < 1000 && b * i < 1000 & c * i < 1000; i++)
		if (a * i > 99 && b * i > 99 && c * i > 99) {
			memset(f, 0, sizeof(f));
			for (int t = a * i; t > 0; t /= 10) f[t % 10]++;
			for (int t = b * i; t > 0; t /= 10) f[t % 10]++;
			for (int t = c * i; t > 0; t /= 10) f[t % 10]++;
			mark = true;
			for (int i = 1; i < 10; i++)
				if (f[i] == 0) {
					mark = false;
					break;
				}
			if (mark) printf("%d %d %d\n", a * i, b * i, c * i), ans++;
		}
	if (!ans) puts("No!!!");
	return 0;
}
