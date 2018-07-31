#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
vector <int>a;
int read()
{
int x=0;char ch;short int neg=0;ch=getchar();
while(!isdigit(ch)){
    neg|=(ch=='-');ch=getchar();
}
while(isdigit(ch)){
    x=x*10+ch-48;ch=getchar();
}
return neg?-x:x;
}
int main()
{
int n,op;
cin>>n;
while(n--)
{
    cin>>op;
    register int x=read();
    switch(op){ 
case(1):a.insert(upper_bound(a.begin(),a.end(),x),x);break;
case(2):a.erase(lower_bound(a.begin(),a.end(),x));break;
case(3): cout<<lower_bound(a.begin(),a.end(),x)-a.begin()+1<<endl;break;
case(4): cout<<a[x-1]<<endl;break;
case(5): cout<<*--lower_
case(6): cout<<*upper_bound(a.begin(),a.end(),x)<<endl;break;
   }
}
return 0;
}