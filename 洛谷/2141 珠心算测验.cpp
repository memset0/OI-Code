#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int a[110];
	long long ans = 0;
	cin >> n;
	for (int i  = 1; i <= n; i++)
		cin >> a[i];
	bool b;
	for (int i = 1; i <= n; i++) {
		b = false;
		for (int j = 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				if (a[j] + a[k] == a[i])
				 b = true;
		if (b) ans++;
	} 
	cout << ans << endl;
	return 0;
}
