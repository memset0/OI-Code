#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, ans = 0, a[maxn];
bool mrk;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (1) {
		mrk = true;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2) {
				mrk = false;
				break;
			} 
			a[i] /= 2;
		}
		if (mrk) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}
