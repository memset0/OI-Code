#include <cstdio>
typedef long long ll;

ll k,L,p,s,w;

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

inline ll fpow(ll a,ll b){
	a%=p; ll res=1;
	while (b){
		if (b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

inline ll inv(ll x){
	return fpow(x,p-2);	
}

int main(){
	read(k),read(L),read(p);
	read(s);
	if (L==1) print(s?1:k%p); else
	if (L==2) print(k%p*((k-1)%p)%p*(s?inv(k):1)%p); else
		print(k%p*((k-1)%p)%p*fpow(k-2,L-2)%p*(s?inv(k):1)%p);
	return 0;
}

