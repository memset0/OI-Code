#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, ans, a[maxn], b[maxn];
void msort(int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r) return ;
    msort(l, mid), msort(mid + 1, r);
    int i = l, j = mid + 1, k = l, r1 = mid, r2 = r;
//	cout << " >>> l = " << l << " r = " << r << endl;
//	for (int i = l; i <= r; i++)
//		cout << a[i] << " ";
//	cout << endl;
    while (i <= r1 && j <= r2) {
        while (i <= r1 && a[i] <= a[j]) b[k++] = a[i++];
        while (j <= r2 && a[j] <= a[i]) b[k++] = a[j++], ans += r1 - i + 1;
    }
    while (i <= r1) b[k++] = a[i++];
    while (j <= r2) b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
//	for (int i = l; i <= r; i++)
//		cout << b[i] << " ";
//	cout << endl;
}
int main() {
//	freopen("sequence.in", "r", stdin);
//	freopen("sequence.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    msort(1, n);
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	cout << endl;
    cout << ans << endl;
    return 0;
}
