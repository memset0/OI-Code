#include <bits/stdc++.h>
using namespace std;
double v = 7, s, x;
int main() {
	cin >> s >> x;
	while (s > x) {
		s -= v;
		v *= 0.98;
	}
	if (s - v < -x) puts("n");
	else puts("y");
	return 0;
}
