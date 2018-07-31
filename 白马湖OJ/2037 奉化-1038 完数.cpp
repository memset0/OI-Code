#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
	cin >> n;
	if (n >= 6) ans = 6;
	if (n >= 28) ans = 28;
	if (n >= 496) ans = 496;
	if (n >= 8128) ans = 8128;
	if (n >= 33550336) ans = 33550336;
	if (n >= 8589869056) ans = 8589869056;
	cout << ans << endl;
	return 0;
}
