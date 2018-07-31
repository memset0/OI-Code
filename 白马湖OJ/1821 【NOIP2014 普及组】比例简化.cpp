#include <bits/stdc++.h>
using namespace std;
int a, b, n, m, l, ans_a, ans_b;
double x, ans_c;
int main() {
	cin >> n >> m >> l;
	ans_c = n + m; 
	for (int i = 1; i <= l; i++) {
		a = i, b = i * m / n;
		if (b > l) b = l;
		x = (a / (double)b) - (n / (double)m);
//		cout << x << endl;
		if (x >= 0 && x < ans_c) {
			ans_a = a;
			ans_b = b;
			ans_c = x;
		}
	}
	cout << ans_a << " " << ans_b << endl;
	return 0;	
}
