#include <bits/stdc++.h>
#define read(n) scanf("%d", &n) 
using namespace std;
const int maxn = 10010;
int a[maxn], f_1[maxn], f_2[maxn];
int n;
int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    a[0] = -1; f_1[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && f_1[j] + 1 > f_1[i]) 
                f_1[i] = f_1[j] + 1;
    a[n+1] = -1; f_2[n+1] = 0;
    for (int i = n; i >= 1; i--)
        for (int j = n+1; j > i; j--)
            if (a[i] > a[j] && f_2[j] + 1 > f_2[i])
                f_2[i] = f_2[j] + 1;
    int maxx = -1;
    for (int i = 1; i <= n; i++)
        if (f_1[i] + f_2[i] > maxx) maxx = f_1[i] + f_2[i];
    printf("%d", n-maxx+1);
    return 0;
} 
