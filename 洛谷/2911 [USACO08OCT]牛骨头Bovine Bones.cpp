#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, f[100];
	memset(f, 0, sizeof(f));
	cin >> a >> b >> c;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				f[i + j + k]++;
	int max = -1, ans;
	for (int i = 3; i < 100; i++)
		if (f[i] > max) {
			max = f[i];
			ans = i;
		}
	cout << ans << endl;
	return 0;
}