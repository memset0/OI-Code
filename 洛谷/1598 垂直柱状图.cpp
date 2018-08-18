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

char c;
int a[26];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	while (c = getchar()) {
		if (c == -1) break;
		if ('A' <= c && c <= 'Z')
			a[c - 'A']++;
	}

	int maxx = 0;
	for (int i = 0; i < 26; i++)
		maxx = max(maxx, a[i]);

	for (int j = maxx; j; j--) {
		for (int i = 0; i < 26; i++) {
			if (i) putchar(' ');
			putchar(a[i] >= j ? '*' : ' ');
		}
		putchar('\n');
	}
	for (int i = 0; i < 26; i++) {
		if (i) putchar(' ');
		putchar('A' + i);
	}
	putchar('\n');

	return 0;
}