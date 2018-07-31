#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn], b[maxn];
long long ans = 0;
void msort(int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) / 2, i = l, j = mid + 1, k = l;
    msort(l, mid);
    msort(mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else {
            ans += mid + 1 - i;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    msort(1, n);
    cout << ans;
    return 0;
}