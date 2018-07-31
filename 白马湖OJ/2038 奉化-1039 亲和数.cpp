#include <bits/stdc++.h> 
using namespace std;
const int maxn = 2000010;
int l, r, s, f[maxn];
int main() {
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		s = 0;
		for (int j = 1; j < i; j++)
			if (i % j == 0) s += j;
		f[i] = s;
	}
	for (int i = l; i <= r; i++)
		if (i != f[i] && i == f[f[i]]) {
			cout << i << " " << f[i] << endl;
			return 0;
		}
	return 0;
}
