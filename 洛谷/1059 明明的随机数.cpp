#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, a, b[maxm];
int main() {
	cin >> n;
	int m = n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (b[a]) m--;
		b[a] = 1;
	}
	cout << m << endl;
	for (int i = 0; i <= 1000; i++)
		if (b[i]) 
			cout << i << " ";
	return 0;
}
