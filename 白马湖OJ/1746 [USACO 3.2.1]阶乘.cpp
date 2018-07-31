#include <bits/stdc++.h>
using namespace std;
const int maxl = 20000;
int main() {
	int n, l = 0, s[maxl];
	memset(s, 0, sizeof(s));
	s[1] = l = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = l; j > 0; j--) {
			s[j] *= i;
			s[j + 1] += s[j] / 10000;
			s[j] %= 10000;
		}
		while (s[l + 1]) l++;
	}
	int k = 1;
	while (!s[k]) k++;
	while (s[k] % 10 == 0) s[k] /= 10;
	cout << s[k] % 10 << endl;
	
	return 0;
}
