#include <bits/stdc++.h>
using namespace std;

int l, r, ll, rr, i, j, k, x, y, z, t, m;
bool mark;

int main() {
	cin >> l >> r >> ll >> rr >> m;
	for (i = ll; i <= rr; i++) {
		t = 0;
		for (k = l; k <= r; k++) {
			if (t > m) break;
			j = i, mark = true;
			x = j % k, j /= k;
			y = j % k, j /= k; 
			if (x == y) {
				mark = false;
			} else while (j > 0) {
				z = j % k, j /= k;
				if (z != x) {
					mark = false;
					break;
				}
				if (j > 0) {
					z = j % k, j /= k;
					if (z != y) {
						mark = false;
						break;
					}
				}
			}
			if (mark) t++;
		}
		if (t == m) {
			printf("%d\n", i);
		}
	}
	return 0;
}
