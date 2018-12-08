#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<ctime>
namespace fast_IO
{
    const int IN_LEN=10000000,OUT_LEN=10000000;
    char ibuf[IN_LEN],obuf[OUT_LEN],*ih=ibuf+IN_LEN,*oh=obuf,*lastin=ibuf+IN_LEN,*lastout=obuf+OUT_LEN-1;
    inline char getchar_(){return (ih==lastin)&&(lastin=(ih=ibuf)+fread(ibuf,1,IN_LEN,stdin),ih==lastin)?EOF:*ih++;}
    inline void putchar_(const char x){if(oh==lastout)fwrite(obuf,1,oh-obuf,stdout),oh=obuf;*oh++=x;}
    inline void flush(){fwrite(obuf,1,oh-obuf,stdout);}
}
using namespace fast_IO;
//#define getchar() getchar_()
//#define putchar(x) putchar_((x))
typedef long long LL;
#define rg register
template <typename T> inline T max(const T a,const T b){return a>b?a:b;}
template <typename T> inline T min(const T a,const T b){return a<b?a:b;}
template <typename T> inline T mind(T&a,const T b){a=a<b?a:b;}
template <typename T> inline T maxd(T&a,const T b){a=a>b?a:b;}
template <typename T> inline T abs(const T a){return a>0?a:-a;}
template <typename T> inline void Swap(T&a,T&b){T c=a;a=b;b=c;}
template <typename T> inline void swap(T*a,T*b){T c=a;a=b;b=c;}
template <typename T> inline T gcd(const T a,const T b){if(!b)return a;return gcd(b,a%b);}
template <typename T> inline T square(const T x){return x*x;};
template <typename T> inline void read(T&x)
{
    char cu=getchar();x=0;bool fla=0;
    while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
    while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
    if(fla)x=-x;  
}
template <typename T> void printe(const T x)
{
    if(x>=10)printe(x/10);
    putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
    if(x<0)putchar('-'),printe(-x);
    else printe(x);
}
inline void judge()
{
//	freopen("isaac.in","r",stdin);
//	freopen("isaac0.out","w",stdout);
}
const int maxn=1000001;
int n;
int belo[maxn],fa[maxn],ha[maxn],hc[maxn],inside[maxn],tot,l,r;
bool vis[maxn];
int mini,maxi;
void dfs(const int u)
{
	if(belo[u])return;
	if(vis[u])
	{
		tot++;
		belo[u]=tot;
		hc[tot]=u;
		return;
	}
	vis[u]=1;
	dfs(fa[u]);
	belo[u]=belo[fa[u]];
}
int main()
{
	judge();
	read(n);
	for(rg int i=1;i<=n;i++)read(fa[i]),inside[fa[i]]++;
	for(rg int i=1;i<=n;i++)
		if(!belo[i])
			dfs(i);
	for(rg int i=1;i<=n;i++)if(!inside[i])ha[belo[i]]++;
	for(rg int i=1;i<=tot;i++)mini+=max(ha[i],(int)(hc[i]!=fa[hc[i]]));
	memset(vis,0,sizeof(vis));
	for(rg int i=1;i<=n;i++)if(!inside[i])belo[++r]=i;
	while(l<r)
	{
		const int u=belo[++l];
		if(vis[u])continue;
		maxi++;
		if(!vis[fa[u]])
		{
			vis[fa[u]]=1;
			if(!(--inside[fa[fa[u]]]))belo[++r]=fa[fa[u]];
		}
	}
	for(rg int i=1;i<=n;i++)
		if(!vis[i]&&inside[i])
		{
			int tot=1;
			vis[i]=1;
			for(rg int j=fa[i];j!=i;j=fa[j])vis[j]=1,tot++;
			maxi+=tot>>1;
		}
	print(n-maxi),putchar(' '),print(n-mini);
	return flush(),0;
}
