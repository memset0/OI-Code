#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int re(){
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*w;
}
int n,m,B,len,Ans,a[N],d[N],b[N],t[N],cnt[N],ans[N];
struct Q{int l,r,id;}q[N];
bool cmp(Q x,Q y){
    if(b[x.l]==b[y.l])
        if(b[x.l]&1)return x.r<y.r;
        else return x.r>y.r;
    return b[x.l]<b[y.l];
}
void add(int i){
    t[cnt[a[i]]]--;
    t[++cnt[a[i]]]++;
    Ans=max(Ans,cnt[a[i]]);
}
void del(int i){
    t[cnt[a[i]]]--;
    if(cnt[a[i]]==Ans&&!t[cnt[a[i]]])Ans--;
    t[--cnt[a[i]]]++;
}
int main(){
	freopen("3.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
    n=re(),m=re();B=sqrt(n);
    for(int i=1;i<=n;i++){
        d[i]=a[i]=re();
        b[i]=(i-1)/B+1;
    }
    sort(d+1,d+n+1);len=unique(d+1,d+n+1)-d-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(d+1,d+len+1,a[i])-d;
    for(int i=1;i<=m;i++)
        q[i]=(Q){re(),re(),i};
    sort(q+1,q+m+1,cmp);
    for(int i=1,l=1,r=0;i<=m;i++){
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        while(l<q[i].l)del(l++);
        while(l>q[i].l)add(--l);
        ans[q[i].id]=Ans;
    }
    for(int i=1;i<=m;i++)printf("%d\n",-ans[i]);
    return 0;
}
