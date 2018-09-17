#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <set>
#define il inline
#define vd void
#define rep(i,x,y) for(register int i=x;i<=y;++i)
#define drp(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
const int Len=2333333,mn=2e5+5;
char buf[Len],*p1=buf,*p2=buf,duf[Len],*q1=duf;
il char gc(); il int rd(); il vd pc(char c); il vd rt(int x); il vd flush();
int n,m,d,t,N,a[mn],ans[mn];
struct P{
    int id,v;
    il int operator <(const P &p)const{return v<p.v;}
}u;
set <P> S;
set <P>::iterator it;
int main(){
    n=N=rd(),m=rd(),d=rd()+1;
    rep(i,1,n) a[i]=rd();
    rep(i,1,n) S.insert((P){i,a[i]});
    while(S.size()){
        ++t,it=S.lower_bound((P){0,1}),u=*it;
        int ti=u.v;
        while(1){
            if(it==S.end()) break;
            ans[u.id]=t,ti+=d,S.erase(it),it=S.lower_bound((P){0,ti}),u=*it;
            if(it!=S.end()) ti=u.v;
        }
    }
    rt(t),pc('\n');
    rep(i,1,n) rt(ans[i]),pc(' ');
    return flush(),0;
}

il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,Len,stdin),p1==p2)?-1:*p1++;}
il int rd(){char c; int f=1;
    while(!isdigit(c=gc())&&c!='-');
    c=='-'?f=-1,c=gc():0; int x=c^48;
    while(isdigit(c=gc())) x=((x+(x<<2))<<1)+(c^48);
    return x*f;
}
il vd pc(char c){q1==duf+Len&&fwrite(q1=duf,1,Len,stdout),*q1++=c;}
il vd rt(int x){x<0?pc('-'),x=-x:0,pc((x>=10?rt(x/10),x%10:x)+48);}
il vd flush(){fwrite(duf,1,q1-duf,stdout);}

