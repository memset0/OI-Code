#include<bits/stdc++.h>
using namespace std;
int n, R[1010];
const double PI=acos(-1.0);
double sum=0.0;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &R[i]);
    sort(R+1,R+n+1);
    for(int i=0;i<=n;i+=2)
        sum-=R[i]*R[i];
    for(int i=1;i<=n;i+=2)
        sum+=R[i]*R[i];
    sum*=PI;
    printf("%.10lf\n",abs(sum));
    return 0;
}