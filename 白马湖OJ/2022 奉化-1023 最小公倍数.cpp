#include <bits/stdc++.h>
using namespace std;
int a, b;
long long GCB(long long a, long long b) {
	if (b == 0) return a;
	return GCB(b, a % b);
}
int main() {
	cin >> a >> b;
	long long c = a / GCB(a, b);
	c *= b;
	cout << c;
}
