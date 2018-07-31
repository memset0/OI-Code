#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort; 

#define MAXN 3005
typedef long long ll;

int n;
ll ans,sx[MAXN],sy[MAXN];

struct Point{
	ll x,y;
	Point operator -(const Point &v)const{
		return (Point){x-v.x,y-v.y};
	}
} a[MAXN],b[MAXN];
typedef Point Vector;

inline bool cmpy(const Point &a,const Point &b){
	return a.y<b.y;
}

inline bool cmpa(const Vector &a,const Vector &b){
	if (a.x*b.y==a.y*b.x) return b.x<a.x;
	else return a.y*b.x<a.x*b.y; 
}

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
	sort(a+1,a+1+n,cmpy);
	for (int i=1;i<=n-2;i++){
		memset(sx,0,sizeof(sx));
		memset(sy,0,sizeof(sy));
		for (int j=i+1;j<=n;j++)
			b[j]=a[j]-a[i];
		sort(b+i+1,b+1+n,cmpa);
		for (int j=i+1;j<=n;j++) sx[j]=sx[j-1]+b[j].x,sy[j]=sy[j-1]+b[j].y;
		for (int j=i+1;j<=n;j++)
			ans+=b[j].x*(sy[n]-sy[j])-b[j].y*(sx[n]-sx[j]);
	}
	if (ans&1) printf("%lld.5\n",ans>>1);
	else printf("%lld.0\n",ans>>1);
	return 0;
}
