#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100010;
const int M=N*40;
struct Task{
    int end,val,tag;
    bool operator < (const Task &rhs) const{
        return end<rhs.end;
    }
    Task(int end,int val,int tag):end(end),val(val),tag(tag){}
    Task(){}
}b[N*3];
struct President_Tree{
    LL sum,size;
    int L,R;
}T[M];
int root[N],n,m,T_cnt=1,totm=0,a[N];
int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while ('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
void insert(int &now,int x,int index,int l=1,int r=n){
    T[T_cnt++]=T[now];now=T_cnt-1;
    T[now].size+=(LL)index;
    T[now].sum+=(LL)index*a[x];
    if (l==r)return;
    int mid=(l+r)>>1;
    if (x<=mid)insert(T[now].L,x,index,l,mid);
        else insert(T[now].R,x,index,mid+1,r);
}
LL query(int now,int k,int l=1,int r=n){
    if (l==r)return T[now].sum/T[now].size*(LL)k;
    int t=T[T[now].L].size,mid=(l+r)>>1;
    if (k<=t)return query(T[now].L,k,l,mid);
        else return T[T[now].L].sum+query(T[now].R,k-t,mid+1,r);
}
int main(){
	freopen("INPUT","r",stdin);
    m=read(),n=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        b[++totm]=Task(x,z,1);
        b[++totm]=Task(y+1,z,-1);
        a[i]=z;
    }
    sort(a+1,a+m+1);
    sort(b+1,b+totm+1);
    root[0]=0;
    for (int i=1,j=1;i<=n;i++){
        root[i]=root[i-1];
        for (;j<=totm && b[j].end==i;j++){
            int rk=lower_bound(a+1,a+n+1,b[j].val)-a;
            insert(root[i],rk,b[j].tag);
        }
    }
    LL ans=1;
    for (int i=1;i<=n;i++){
        LL x=read(),a=read(),b=read(),c=read();
        LL kth=(a*ans+b)%c+1;
        printf(">>> %lld %lld\n", x, kth);
        if (kth>=T[root[x]].size)ans=T[root[x]].sum;
            else ans=query(root[x],kth);
        printf("%lld\n",ans);
    }
    return 0;
}
