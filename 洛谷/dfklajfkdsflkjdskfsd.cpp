// luogu-judger-enable-o2

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
namespace FastIO  {
    const size_t str = 1 << 20;
  
    struct Reader  {
        char buf[str], *s, *t;
        Reader ( ) : s( ), t( ), buf() {    }
        inline char pick ( )  {
            return (s == t) ? ( t = buf + fread ( s = buf, 1, str , stdin ), *s++ ) : ( *s++ );
        }
  
        template < class T >
        inline Reader& operator >> ( T& x )  {
            static char ch;
            static short opt;
            opt = (ch != 45);
            while ( !isdigit ( ch = pick () ) && (ch ^ -1) && ( ch ^ 45 ) );
            if ( ch == -1 )     return *this;
            if ( ch == 45 )     {   opt = 0; ch = pick ();   }
            for ( x = -48 + ch; isdigit ( ch = pick () ); ( x *= 10 ) += ch - 48 );
            opt ? 1 : x = -x;
            return *this;
        }
  
    } cin;
  
    struct Writer  {
        char buf[str], *s, *t;
        Writer () : s ( buf ), t( buf + str ), buf ( ) {    }
        ~Writer () { fwrite( buf, 1, s - buf, stdout ); }
  
        inline void echo ( char c )  {
            ( s == t ) ? ( fwrite ( s = buf, 1, str, stdout ), *s++ = c ) : ( *s++ = c );
        }
  
        inline Writer& operator << ( long long x )  {
            if( !x ) return echo( 48 ), *this;
            static int t[21], top;
            if (x < 0) x = -x, echo ( '-' );
            while ( x ) t[++top] = x % 10, x /= 10;
            while ( top ) echo(t[top--] + 48);
            return *this;
        }
        inline Writer& operator << (const char* s)  {
            while ( *s ) echo( *s++ ) ;
            return *this;
        }
    } cout;
    const char *endl = "\n";
} 
 
using FastIO::cin;
using FastIO::cout;
using FastIO::endl;

const long long N=5e4+7,M=100;
const long long power=1;
bool flag,used[N][M];
long long n,m,p,k,s,q,e,opt,ans,w[N],f[M],t[N][M],dp[N][M];
struct tree{long long a,b,c,sum,tag;}tr[N<<2];
inline long long read()
{
    long long num=0; char g=getchar();
    while(g<48||57<g) g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
    return num; 
}
inline long long Max(long long a,long long b) {if(a>b) return a; return b;}
inline long long Min(long long a,long long b) {if(a<b) return a; return b;}
inline long long pow(long long a,long long b,long long c)
{
    long long u=0,ans=1;
    while(true)
    {
        if(b&(power<<u)) {if(ans*a>=c) flag=true; ans=(ans*a)%c;}
        u++; if(b<(power<<u)) break;
        if(a*a>=c) flag=true; a=(a*a)%c;
    }
    return ans;
}
inline long long phi(long long u) {long long ans=u,tot=u; for(long long i=2;i<=sqrt(u);i++) if(!(tot%i)) {ans=(ans/i)*(i-1); while(!(tot%i)) tot/=i;} if(tot>1) ans=ans/tot*(tot-1); return ans;}
inline long long find(long long r,long long a,long long b)
{
    if(!used[r][a]) return pow(k,find(r,a-1,phi(b)),b)+b;
    else if(t[r][a]>=b) return (t[r][a]%b)+b;
    else return t[r][a]%b;
}
void build(long long a,long long b,long long c)
{
    tr[c].a=a,tr[c].b=b,tr[c].c=(a+b)>>1; 
    if(a==b) {tr[c].sum=dp[a][0]; return;}
    build(tr[c].a,tr[c].c,(c<<1));
    build(tr[c].c+1,tr[c].b,(c<<1)+1);
    tr[c].sum=tr[c<<1].sum+tr[(c<<1)+1].sum;
}
void change(long long a,long long b,long long c)
{
    if(tr[c].a==tr[c].b&&tr[c].tag<opt)
    {
        tr[c].tag++,tr[c].sum=dp[a][tr[c].tag];c=c>>1;
        while(c>0) tr[c].sum=(tr[c<<1].sum+tr[(c<<1)+1].sum)%p,tr[c].tag=Min(tr[c<<1].tag,tr[(c<<1)+1].tag),c=c>>1; 
    }
    else if(tr[c].a==tr[c].b) return;
    if(tr[c].a<=b&&a<=tr[c].c&&tr[c<<1].tag<opt) change(a,Min(b,tr[c].c),(c<<1));
    if(tr[c].c<b&&a<=tr[c].b&&tr[(c<<1)+1].tag<opt)  change(Max(a,tr[c].c+1),b,(c<<1)+1);
}
void search(long long a,long long b,long long c)
{
    if(tr[c].a==a&&tr[c].b==b) {ans=(ans+tr[c].sum)%p; return;}
    if(tr[c].a<=b&&a<=tr[c].c) search(a,Min(b,tr[c].c),(c<<1));
    if(tr[c].c<b&&a<=tr[c].b)  search(Max(a,tr[c].c+1),b,(c<<1)+1);
}
int main()
{
    long long a,b,c;
    cin >> n >> m >> p >> k; e=p,opt+=5;
    while(phi(e)>1) e=phi(e),opt++,e=phi(e); 
    for(long long i=1;i<=n;i++) cin >> dp[i][0], t[i][0] = dp[i][0], used[i][0]=true;
    for(long long i=1;i<=n;i++)
        for(long long x=1;x<=opt;x++) {flag=false; t[i][x]=pow(k,t[i][x-1],p); if(flag) {t[i][x]=0; break;} used[i][x]=true;}
    for(long long i=1;i<=n;i++)
        for(long long x=1;x<=opt;x++)
            dp[i][x]=pow(k,find(i,x-1,phi(p)),p);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b >> c;
        if(!a) change(b,c,1);
        else ans=0,search(b,c,1),cout <<ans << endl;
    }
    return 0;
}
