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

int opt, w, c, sw, sc;
set < int > Set;
map < int, int > Map;
set < int > ::iterator it;

int main() {
//	freopen("INPUT", "r", stdin);
	
	while (scanf("%d", &opt) != EOF) {
		switch (opt) {
			case 1:
				w = read(), c = read();
				if (!Set.count(c)) {
					Set.insert(c);
					Map[c] = w;
					sw += w, sc += c;
				}
				break;
			case 2:
				if (Set.size()) {
					it = --Set.end();
					sw -= Map[*it], sc -= *it;
					Set.erase(it);
				}
				break;
			case 3:
				if (Set.size()) {
					it = Set.begin();
					sw -= Map[*it], sc -= *it;
					Set.erase(it);
				}
				break;
			case -1:
				printf("%d %d\n", sw, sc);
				break;
		}
	}
	
	return 0;
}
