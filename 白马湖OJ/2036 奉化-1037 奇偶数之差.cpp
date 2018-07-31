#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r, s1, s2;
int main() {
	cin >> n >> m;
	if (n % 2 == 0) l = n + 1;
	else l = n;
	if (m % 2 == 0) r = m - 1; 
	else r = m;
	s1 = (l + r) * ((r - l) / 2 + 1) / 2;
	if (n % 2 == 0) l = n;
	else l = n + 1;
	if (m % 2 == 0) r = m;
	else r = m - 1;
	s2 = (l + r) * ((r - l) / 2 + 1) / 2;
	cout << (s1 - s2) << endl;
	return 0;
} 
