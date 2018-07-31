#include <iostream>
#include <cstdio>
using namespace std;
int f(int);
int mi(int);
int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}
int fang(int k)
{
    int s = 1;
    for (int i = 1; i <= k; i++)
    {
        s *= 2;
    }
    return s;
}
int mi(int n)
{
    int k = 0, s = 1;
    while (s <= n) 
    {
        k++;
        s = s * 2;
    }
    if (fang(k) <= n) return k;
    else return k-1;
}
int f(int n)
{
    if (n <= 0) return -1;
    if (n == 1) {printf("2(0)"); return 0;}
    if (n == 2) {printf("2"); return 0;}
    if (n == 3) {printf("2+2(0)"); return 0;}
    if (n == 4) {printf("2(2)"); return 0;}
    int t = mi(n);
    int tt = fang(t);
    if (tt == n)
    {
        printf("2(");
        f(t);
        printf(")");
    }
    else
    {
        printf("2(");
        f(t);
        printf(")+");
        f(n - tt);
    }
    return 0;
}
