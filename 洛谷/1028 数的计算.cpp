#include <bits/stdc++.h>
using namespace std;
long long n, f[1010] = {1};
long long cal(long long k) {
	if (f[k]) return f[k];
	int sum = 0;
	for (int i = 0; i * 2 <= k; i++)
		sum += cal(i);
	return f[k] = sum;
}
int main() {
	cin >> n;
	cout << cal(n) << endl;
	return 0;
}
