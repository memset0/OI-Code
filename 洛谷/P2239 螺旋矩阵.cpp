#include <bits/stdc++.h> 
using namespace std;
const int maxn = 30010;
int getn(int n, int i, int j) {
	int x = min(i, min(j, min(n - i + 1, n - j + 1))), 
		y = (x - 1) * 4 * (n - x + 1) + 1, ans;
	if (x == i) ans = y + n * 0 + 0 - x * 1 + j;
	else if (x == n - j + 1) ans = y + n * 1 + 1 - x * 3 + i;
	else if (x == n - i + 1) ans = y + n * 3 + 3 - x * 5 - j;
	else if (x == j) ans = y + n * 4 + 4 - x * 7 - i;
	return ans;
}
int main() {
	int n, i, j;
	cin >> n >> i >> j;
	cout << getn(n, i, j);
	return 0;
}