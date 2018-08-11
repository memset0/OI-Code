// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, opt;

struct Splay {
	
	int tot, points;
	struct node {
		
	} e[maxn];
};

int main() {
	
	n = read();
	while (n--) {
		opt = read();
		switch(opt) {
			case 1: s.insert(read()); break;
			case 2: s.erase(read()); break;
			case 3: printf("%d\n", s.rank(read())); break;
			case 4: printf("%d\n", s.ar
		}
	}
	
	return 0;
}

