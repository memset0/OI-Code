#include<bits/stdc++.h>
using namespace std;
const int maxn = 30010, maxw = 210;
int n, w, a[maxn], f[maxw];
long long cnt = 0;
int main() {
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), f[a[i]]++;
	for (int i = 1; i <= w; i++) {
		for (int j = w - i; j > i; j--)
			if (f[j] >= f[i]) {
				cnt += f[i];
				f[j] -= f[i];
				f[i] = 0;
			}
			else {
				cnt += f[j];
				f[i] -= f[j];
				f[j] = 0;
			}
		if (f[i] > 0) {
			if (i <= w / 2) cnt += (f[i] + 1) / 2;
			else cnt += f[i];
		}
	}
	cout << cnt;
	return 0;
}
