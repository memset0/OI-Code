#include<bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N=105;
ll n,a[N],sum,s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    sum/=n;
    for(int i=1;i<=n;i++)a[i]-=sum,s[i]=s[i-1]+a[i];
    sort(s+1,s+n+1);
    sum=0;
    for(int i=1;i<=n;i++)sum+=abs(s[n/2+1]-s[i]);
    cout<<sum;
    return 0;
}