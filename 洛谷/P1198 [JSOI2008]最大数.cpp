#include<iostream>
using namespace std;
typedef long long LL;
LL m,d,maxn[800800],t=0,i,j,len=0;
char op;
void edit(LL l,LL r,LL pos,LL value,LL t){
    if(l==r) maxn[t]=value;
    else{
        LL mid=(l+r)>>1;
        if(mid>=pos) edit(l,mid,pos,value,t<<1);
        if(mid<pos) edit(mid+1,r,pos,value,t<<1|1);
        maxn[t]=max(maxn[t<<1],maxn[t<<1|1]);
    }
}
LL query(LL L,LL R,LL l,LL r,LL t){
    if(L>=l && R<=r) return maxn[t];
    LL mid=(L+R)>>1,left=0,right=0;
    if(mid>=l) left=query(L,mid,l,r,t<<1);
    if(mid<r) right=query(mid+1,R,l,r,t<<1|1);
    return max(left,right);
}
int main(){
    cin>>m>>d;
    for(LL i=1;i<=m;i++){
        LL x;
        cin>>op>>x;
        if(op=='Q')
            if(x==0) cout<<(t=0)<<endl;
            else cout<<(t=query(1,m,len-x+1,len,1))<<endl;
        else{
            len++;
            edit(1,m,len,(x+t)%d,1);
        }
    }
    return 0;
}