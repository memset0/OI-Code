#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
bool check(long long x) {
	if (((long long)sqrt(x)) * ((long long)sqrt(x)) == x) return true;
	return false;
}
long long calc(long long left, long long right) {
	return (left + right) * (right - left + 1) / 2;
}
int main() {
	cin >> n >> k;
	for (long long i = 1; i + k - 1 <= n; i++) {
		if (check(calc(i, i + k - 1))) 
			ans++;
	}
	cout << ans << endl;
	return 0;
}
