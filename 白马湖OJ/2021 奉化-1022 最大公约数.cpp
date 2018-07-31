#include <bits/stdc++.h>
using namespace std;
int a, b;
int GCB(int a, int b) {
	if (b == 0) return a;
	return GCB(b, a % b);
}
int main() {
	cin >> a >> b;
	cout << GCB(a, b);
}
