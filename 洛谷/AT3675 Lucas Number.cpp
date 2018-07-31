#include <bits/stdc++.h>
using namespace std;
int n;
long long f[87];
int main() {
	f[0] = 2, f[1] = 1;
	for (int i = 2; i < 87; i++)
		f[i] = f[i - 1] + f[i - 2];
	cin >> n;
	cout << f[n] << endl;
	return 0;
}
