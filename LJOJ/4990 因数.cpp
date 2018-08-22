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

const int mt = 26;
ll f[mt] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 
	59, 61, 67, 71, 73, 79, 83, 89, 97
};
ll lim[mt];

int pos, tpos, cnt, mx1, mx2, b, k;
ll a, tmp;

struct node {
	ll a;
	int b;
	bool operator < (const node &b) const {
		return a < b.a;
	}
};

node now, nxt;
set < node > s;
vector < node > v;
vector < set < node > ::iterator > r;

int main() {
	// freopen("ans.txt", "w", stdout);
	
	for (int i = 0; i < mt; i++)
		lim[i] = (0x7fffffffffffffffLL) / f[i];
	
	k = read();
	// k = 666;

	now.a = 1, now.b = 1;
	s.insert(now);
	for (int i = 1; i <= k; i++) {
		r.clear();
		now = *s.begin();
		s.erase(s.begin());
		v.push_back(now);
		if (i == k)
			printf("%lld\n", now.a);
		for (int i = 1; i < mt; i++)
			if (now.a <= lim[i]) {
				nxt = now;
				tmp = nxt.a, cnt = 0;
				while (tmp % f[i] == 0) {
					tmp /= f[i];
					cnt++;
				}
				nxt.a = nxt.a * f[i];
				nxt.b = nxt.b / (cnt + 1) * (cnt + 2);
				s.insert(nxt);
			}
		mx1 = mx2 = 0;
		for (auto now = v.begin(); now != v.end(); now++) {
			a = (*now).a, b = (*now).b;
			if (b >= mx1) mx2 = mx1, mx1 = b;
			else if (b > mx2) mx2 = b;
		}
		// for (auto now = s.begin(); now != s.end(); now++) {
		// 	printf("> %lld %d\n", (*now).a, (*now).b);
		// }
		for (auto now = s.begin(); now != s.end(); now++) {
			cnt = 0;
			a = (*now).a, b = (*now).b;
			if (b < mx1) cnt++;
			if (b < mx2) cnt++;
			if (b >= mx1) mx2 = mx1, mx1 = b;
			else if (b > mx2) mx2 = b;
			if (cnt == 2)
				r.push_back(now);
		}
		for (auto it = r.begin(); it != r.end(); it++)
			s.erase(*it);
	}
	
	return 0;
}
