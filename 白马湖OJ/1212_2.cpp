#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int a[100];
int f(int k, int num)
{
    if (k == n)
    {
        if (a[k] == num) return true;
        else return false;
    } 
    else
    if (f(k + 1, num) || f(k + 1, num - a[k])) return true;
    else return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (f(1, m)) cout << "YES";
    else cout << "NO";
}
