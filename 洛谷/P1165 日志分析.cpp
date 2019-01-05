#include<bits/stdc++.h>
using namespace std;   
int n, x, y, t = 0, f[200010];   
int main()
{
    cin >> n;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        if (x==0)
        {
            cin>>y;
            t++;
            f[t]=max(f[t-1],y);
        }
        if (x == 1) if (t != 0) t--;
        if (x == 2) cout << f[t] << endl;
    } 
    return 0;   
}  