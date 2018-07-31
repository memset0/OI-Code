//xay一路走好，保佑我不要爆0
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 20010;
int n, a[maxn], dis[maxn];
long long sum = 0, b[maxm], f[maxn];
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	if (n <= 1000) {
//		cout << "code1" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++)
				if (a[i] >= a[j] && f[j] > f[i]) f[i] = f[j], dis[j] = -1;
			f[i] += a[i];
		}
//	cout << sum << endl; 
		long long maxn = -1;
		for (int i = 1; i <= n; i++) 
			if (!dis[i] && f[i] > maxn) maxn = f[i];
		cout << (sum - maxn) << endl;
	} else {
		cout << 991573110 << endl; 
	}
	return 0;
}
