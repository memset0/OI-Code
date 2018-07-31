#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	for (m = 1; n > m; n -= m, m++);
	if (m % 2) printf("%d/%d\n", m + 1 - n, n);
	else printf("%d/%d\n", n, m + 1 - n);
	return 0;
}
