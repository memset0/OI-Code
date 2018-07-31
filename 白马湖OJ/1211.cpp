#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int s[1020];
int f(int n)
{
    if (s[n] != -1) return s[n];
    int sum = 0;
    for (int i = 1; i <= n/2; i++)
    {
        sum += f(i);
    }
    s[n] = (sum + 1);
    return (sum + 1);
}
int main()
{
    memset(s, -1, sizeof(s));
    s[0] = 1;
    s[1] = 1;
    s[2] = 2;
    s[3] = 2;
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}
  
