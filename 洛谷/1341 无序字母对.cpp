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

int n, m, s, cnt, G[60][60], ind[60];
vector < int > vt;

char readc() {
	char c = getchar();
	while (!isupper(c) && !islower(c)) c = getchar();
	return c;
}

int convert(char c) {
	if (isupper(c)) return c - 'A' + 1;
	if (islower(c)) return c - 'a' + 27;
	return -1;
}

char convert(int x) {
	if (x < 27) return x - 1 + 'A';
	if (x > 26) return x - 27 + 'a';
	return -1;
}

void dfs(int u) {
	for (int i = 1; i <= n; i++) {
		if (G[u][i]) {
			G[u][i] = G[i][u] = 0;
			dfs(i);
		}
	}
	vt.push_back(u); 
}

int main() {
	
	n = 52, m = read();
	for (int i = 1; i <= m; i++) {
		int u = convert(readc()), v = convert(readc());
		G[u][v] = G[v][u] = 1;
		ind[u]++, ind[v]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (ind[i] & 1) {
			if (!s) s = i;
			cnt++;
		}
	if (cnt && cnt ^ 2) {
		puts("No Solution");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (ind[i]) {
			if (!s) s = i;
			break;
		}
	dfs(s);
	
	for (vector < int > ::reverse_iterator it = vt.rbegin();
				it != vt.rend();
				it++)
		putchar(convert(*it));

	return 0;
}

