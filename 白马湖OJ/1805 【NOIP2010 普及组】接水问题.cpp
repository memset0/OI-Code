#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxm = 110;
int n, m, a[maxn], b[maxm], ans = -1;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int i = 1, k = 1;
    while (k <= n)
    {
        for (int j = 1; j <= m; j++)    
            if (b[j] < i)
                b[j] += a[k++];
        i++;
    }
    for (int i = 1; i <= m; i++)    
        if (b[i] > ans) ans = b[i];
    cout << ans;
    return 0;
}
