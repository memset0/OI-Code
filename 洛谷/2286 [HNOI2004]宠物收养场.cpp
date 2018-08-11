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

const int inf = 2e9 + 10;
int n, x, opt, ans;
set < int > pet, pep;
set < int > ::iterator it, bfr, aft;

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read();
	pet.insert(inf), pet.insert(-inf);
	pep.insert(inf), pep.insert(-inf);
	for (int i = 1; i <= n; i++) {
		opt = read();
		if (opt) {
			// ÈË
			x = read();
			if (pet.size() == 2) pep.insert(x);
			else if (pet.size() == 3) {
				it = ++pet.begin();
				ans += abs(x - (*it));
				pet.erase(it);
			} else {
				aft = pet.upper_bound(x);
				bfr = --aft;
				if ((x - *aft) <= (*bfr - x)) {
					ans += x - *aft;
					pet.erase(aft);
				} else {
					ans += *bfr - x;
					pet.erase(bfr);
				}
			}
		} else {
			// ¹· 
			x = read();
			if (pep.size() == 2) pet.insert(x);
			else if (pep.size() == 3) {
				it = ++pep.begin();
				ans += abs(x - (*it));
				pep.erase(it);
			} else {
				aft = pep.upper_bound(x);
				bfr = --aft;
				if ((x - *aft) <= (*bfr - x)) {
					ans += x - *aft;
					pep.erase(aft);
				} else {
					ans += *bfr - x;
					pep.erase(bfr);
				}
			}
		}
		if (ans > 1000000)
			ans %= 1000000;
	}
	printf("%d\n", ans);
	
	return 0;
}
