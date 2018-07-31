#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (s == "TAKAHASHIKUN") ans++;
		else if (s == "Takahashikun") ans++;
		else if (s == "takahashikun") ans++;
		else if (s == "TAKAHASHIKUN.") ans++;
		else if (s == "Takahashikun.") ans++;
		else if (s == "takahashikun.") ans++;
	}
	cout << ans << endl;
	return 0;
}
