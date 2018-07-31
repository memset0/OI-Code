#include <bits/stdc++.h>
using namespace std;
double s = 0, k;
int main() {
	cin >> k;
	int i = 1;
	while (s <= k) {
		s += 1.0 / i;
		i++;
	}
	cout << i - 1 << endl;
	return 0;
}

