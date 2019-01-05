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

int n, x, opt, tag, ans;
set < int > s;
set < int > ::iterator l, r, it;

void get(int x, set < int > ::iterator it) {
//	printf("%d(%d) => %d(%d)\n", x, tag ^ 1, *it, tag);
	ans = (ans + abs(*it - x)) % 1000000;
	s.erase(it);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	opt = read(), x = read();
	tag = opt, s.insert(x);
	for (int i = 2; i <= n; i++) {
		opt = read(), x = read();
//		printf(">>> %d %d : %d : ", opt, x, tag);
//		for (auto it = s.begin(); it != s.end(); it++)
//			printf("%d ", *it);
//		puts("");
		if (opt == tag) {
			s.insert(x);
		} else {
			if (!s.size()) {
				tag = opt;
				s.insert(x);
			} else {
				it = s.lower_bound(x);
				if (it == s.end()) {
					get(x, --it);
				} else if (*it == x) {
					get(x, it);
				} else {
					if (it == s.begin()) {
						get(x, it);
					} else {
						r = it, l = --it;
						if (x - *l <= *r - x) get(x, l);
						else get(x, r);
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
