#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int m, t, j;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &j);
        t = a[j];   
        for (int i = j; i <= n-1; i++)
            a[i] = a[i+1];
    }
    printf("%d", a[1]);
    for (int i = 2; i <= (n - m); i++)
        printf(" %d", a[i]);
    return 0;
}
