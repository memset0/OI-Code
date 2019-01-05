#include<bits/stdc++.h>
using namespace std;
long long a[3];
long long q,w;
long long gcd(long long a,long long b) {
    return b==0?a:gcd(b,a%b);
}
int main()
{
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a,a+3);
    q=a[0]/gcd(a[0],a[2]);
    w=a[2]/gcd(a[0],a[2]);
    cout<<q<<"/"<<w;
    return 0;
}