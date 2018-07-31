#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 100010;
int n, ans, a[maxn], b[maxm];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[a[i]]++;
	for (int i = 1; i <= 1e5; i++)
		while (b[i] && b[i+1] && b[i+2])
		{
			ans++;
			b[i]--;
			b[i+1]--;
			b[i+2]--;
		}
	cout << ans << endl;
	return 0;
}
