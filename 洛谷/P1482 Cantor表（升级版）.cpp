#include<bits/stdc++.h>
using namespace std;
int g(int a,int b) {
	return b==0?a:g(b,a%b);
}
int a,b,x,y,s;
char m,n;
int main() {
    cin>>a>>m>>b;
    cin>>x>>n>>y;
    x*=a;y*=b;s=g(x,y);
    x/=s;y/=s;
    cout<<y<<" "<<x;
    return 0;
}