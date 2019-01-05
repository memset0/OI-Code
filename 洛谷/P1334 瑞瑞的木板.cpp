#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll hep[20010], len = 1;
ll put(ll n)
{
    ll j = len;
    hep[len++] = n;
    while (hep[j] < hep[j/2] && j > 1) 
        swap(hep[j], hep[j/2]), j /= 2;
}
ll get()
{
    ll ret = hep[1], i, j = 1;
    hep[1] = hep[--len];
    while (j*2 < len)
    {
        if (hep[j*2] < hep[j*2+1]) i = j * 2;
        else i = j * 2 + 1;
        if (hep[j] > hep[i]) swap(hep[i], hep[j]), j = i;
        else return ret;
    }
    return ret; 
}
int main()
{
    ll n, temp;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &temp), put(temp);
    ll a, b, ans = 0;
    for (ll i = 1; i < n; i++)
    {
        a = get();
        b = get();
        //printf("%d %d\n", a, b);
        ans += a + b;
        put(a + b);
    }
    printf("%lld", ans);
    return 0;
} 