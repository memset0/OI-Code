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

char readc() {
	char c = getchar();
	while (c != 'D' && c != 'Q' && c != 'R') c = getchar();
	return c;
}

const int maxn = 50010;
int n, m, x;
char opt; 
set < int > s;
vector < int > v;
set < int > ::iterator l, r, it;

int query(int x) {
	it = s.lower_bound(x);
	if (*it == x) return 0;
//	printf("%d\n", *it);
	r = it, l = --it;
//	printf("%d %d\n", *l, *r);
	return (*r - *l - 1);
}

int main() {
//	freopen("INPUT", "r", stsdin);
	
	n = read(), m = read();
	s.insert(0), s.insert(n + 1);
	for (int i = 1; i <= m; i++) {
		opt = readc();
		switch (opt) {
			case 'D':
				x = read();
				s.insert(x);
				v.push_back(x);
				break;
			case 'R':
				x = *v.rbegin();
				s.erase(x);
				v.pop_back();
				break;
			case 'Q':
				x = read();
				printf("%d\n", query(x));
				break;
		}
	}
	
	return 0;
}
