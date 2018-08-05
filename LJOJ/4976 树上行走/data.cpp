#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int n, m, opt, cnt, dep, dep1, dep2, s[5] = {'1', '2', 'U', 'L', 'R'};

void putc(char c) {
	if (c == '1') dep1++, dep++;
	if (c == '2') dep2++, dep++;
	if (c == 'U') {
		if (dep < 3) return;
		dep--;
	}
	if (c == 'L') {
		if (dep2 < 3) return;
		dep2--;
	}
	if (c == 'R') {
		if (dep1 < 3) return;
		dep1--;
	}
	putchar(c);
	cnt++;
}

int main() {
	srand(GetTickCount());
//	freopen("data.txt", "w", stdout);
	n = m = 100000;
	cnt = dep = dep1 = dep2 = 0;
	for (int i = 1; cnt <= n; i++) {
		putc(s[rand() % 5]);
	}
	putchar('\n');
	cnt = 0;
	cnt = dep = dep1 = dep2 = 0;
	for (int i = 1; cnt <= n; i++) {
		putc(s[rand() % 5]);
	}
	putchar('\n');
	return 0;
}

